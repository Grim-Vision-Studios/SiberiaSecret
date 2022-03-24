// Copyright 2022, Malachias Harris, All rights reserved


#include "Components/HookComponent.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/Actor.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/KismetSystemLibrary.h>
#include "Engine/EngineTypes.h" // For collison object types.

// Sets default values for this component's properties
UHookComponent::UHookComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	struct ConstructorHelpers::FObjectFinder<UCurveFloat>CurveFloat(TEXT("/Game/InStudio/Blueprints/SeverCombat/Blueprints/CF_Hook"));
	struct ConstructorHelpers::FObjectFinder<UCurveFloat>CurveFloat2(TEXT("/Game/InStudio/Blueprints/SeverCombat/Blueprints/CF_Pull"));


	if (CurveFloat.Object)
	{
		HookCurve = CurveFloat.Object;
	}

	if (CurveFloat2.Object)
	{
		PullCurve = CurveFloat2.Object;
	}

	hookDelay = 1.5f;
	MaxHookdistance = 1000;
	HookRadius = 50.0f;
	bHasHookLocation = false;
	bHasPulled = false;
}


// Called when the game starts
void UHookComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	// Hookable.
	OnT_FinishHook.BindDynamic(this, &UHookComponent::T_HookFinish);
	TimelineProgress.BindDynamic(this, &UHookComponent::T_HookProgress);
	T_Hooked.AddInterpFloat(HookCurve, TimelineProgress);
	T_Hooked.SetTimelineFinishedFunc(OnT_FinishHook);
	T_Hooked.SetLooping(false);

	//Pullable.
	OnT_FinishPull.BindDynamic(this, &UHookComponent::T_PullFinish);
	TimelineProgressPull.BindDynamic(this, &UHookComponent::T_PullProgress);
	T_Pull.AddInterpFloat(PullCurve, TimelineProgressPull);
	T_Pull.SetTimelineFinishedFunc(OnT_FinishPull);
	T_Pull.SetLooping(false);
	
}


// Called every frame
void UHookComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	T_Hooked.TickTimeline(DeltaTime);
	T_Pull.TickTimeline(DeltaTime);
}

bool UHookComponent::TraceForPhysicsBodiesLine(UCameraComponent* CameraComp, FHitResult& HitActor, UPrimitiveComponent*& HitComponent)
{
	const FVector StartLocation = CameraComp->GetComponentLocation();
	const FVector EndLocation = CameraComp->GetComponentLocation() + CameraComp->GetForwardVector() * MaxHookdistance;

	// Interactable objects.
	TArray<TEnumAsByte<EObjectTypeQuery>> InteractableObjects{
		EObjectTypeQuery::ObjectTypeQuery8,	// Hookable object type. 8
		EObjectTypeQuery::ObjectTypeQuery9  // Pullable object type. 9
	};

	// Ignore Actors
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(GetOwner());
	FHitResult HitResult;


	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, "LineTraceing");

	const bool Hit = UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), StartLocation, EndLocation, HookRadius,
		InteractableObjects, false, IgnoreActors, EDrawDebugTrace::ForDuration, HitResult, true);

	if (Hit)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Orange, "Hit");
		HitActor = HitResult;
		HitComponent = HitResult.GetComponent();
		HitActorLocation = HitResult.GetActor()->GetActorLocation();

		if (HookDirectionCheck(HitResult))
		{
			bHasHookLocation = true;
		}

		// Checking for the static mesh actor object type.
		switch (UEngineTypes::ConvertToObjectType(HitResult.GetComponent()->GetCollisionObjectType()))
		{
		case EObjectTypeQuery::ObjectTypeQuery8: // Hookable objects

			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Purple, TEXT("Hookable!"));

			break;

		case EObjectTypeQuery::ObjectTypeQuery9: // Pullable objects

			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Purple, TEXT("Pullable!"));
			PullTowards(HitResult.GetActor());
			break;
		}

		return true;
	}
	return false;
}

void UHookComponent::T_HookProgress(float value)
{
	FVector HitLocation = HitActorLocation;
	HitLocation.Z = HitActorLocation.Z + 100;

	if (GetOwner()->GetActorLocation() == HitLocation)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Cyan, "Done");
		bHasHookLocation = false;
		TimerHandel.Invalidate();
	}


	FVector NewLocation = FMath::Lerp(OwnerLoaction, HitLocation, value);
	GetOwner()->SetActorLocation(NewLocation);
}

void UHookComponent::T_HookFinish()
{
	bHasHookLocation = false;
	GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Emerald, "Finish");
}

void UHookComponent::T_PullProgress(float value)
{
	FVector HitLocation = hitActor->GetActorLocation();
	if (HitLocation.Equals(OwnerLoaction, 30.0f))
	{
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Emerald, "At Loction!!!!!");
		TimerHandel.Invalidate();
		T_Pull.Stop();
		OnT_FinishPull.Execute();
	}
	FVector NewLocation = FMath::Lerp(HitLocation, OwnerLoaction, value);
	hitActor->SetActorLocation(NewLocation);
}

void UHookComponent::T_PullFinish()
{
	bHasPulled = false;
	GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Emerald, "Finish");
	Cast<UPrimitiveComponent>(hitActor->GetRootComponent())->SetSimulatePhysics(true);
}

bool UHookComponent::HookDirectionCheck(FHitResult HitResult)
{
	float dotDirection = FVector::DotProduct(GetOwner()->GetActorForwardVector(), HitResult.GetActor()->GetActorRightVector());
	if (dotDirection < -0.2)
	{
		HitActorLocation.X = HitResult.Location.X;
	}
	else
	{
		HitActorLocation.Y = HitResult.Location.Y;
	}

	float hookDistance = FVector::Dist2D(HitActorLocation, GetOwner()->GetActorLocation());
	//	GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Orange, FString("Distance: ") + FString::SanitizeFloat(hookDistance), true, FVector2D(2, 2));

	if (hookDistance <= 90)
	{
		//bHasHookLocation = true;
		return true;
	}

	return false;
}

void UHookComponent::HookTowards()
{
	if (bHasHookLocation == false)
	{
		//	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "Nothing hit.");
		return;
	}
	FTimerDelegate TimeDelegate;

	TimeDelegate.BindLambda([&] {
		T_Hooked.PlayFromStart();
		});


	OwnerLoaction = GetOwner()->GetActorLocation();
	GetWorld()->GetTimerManager().SetTimer(TimerHandel, TimeDelegate, 0.2, false);
}

void UHookComponent::PullTowards(AActor* Actor)
{
	if (bHasHookLocation == true) { return; }
	hitActor = Actor;
	hitActor->SetActorLocation(FVector(
		hitActor->GetActorLocation().X, hitActor->GetActorLocation().Y, hitActor->GetActorLocation().Z));
	hitActor->DisableComponentsSimulatePhysics();

	FTimerDelegate TimeDelegate;

	TimeDelegate.BindLambda([&] {
		T_Pull.PlayFromStart();
		});

	OwnerLoaction = GetOwner()->GetActorLocation();

	float dotDirection = FVector::DotProduct(GetOwner()->GetActorForwardVector(), hitActor->GetActorForwardVector());
	FMath::DegreesToRadians<float>(dotDirection);
	//dotDirection = FMath::RoundToFloat(dotDirection);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Orange, FString::SanitizeFloat(dotDirection));

	// Move to location.
	OwnerLoaction = GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * 400;

	OwnerLoaction.Z = hitActor->GetActorLocation().Z;
	GetWorld()->GetTimerManager().SetTimer(TimerHandel, TimeDelegate, 0.2, false);
}
