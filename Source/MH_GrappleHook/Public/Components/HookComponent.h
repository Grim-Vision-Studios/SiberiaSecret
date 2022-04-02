// Copyright 2022, Malachias Harris, All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include <Components/TimelineComponent.h>
#include "HookComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MH_GRAPPLEHOOK_API UHookComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHookComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", DisplayName = "Hook Distance"))
		float MaxHookdistance;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true", DisplayName = "Hook Radius"))
		float HookRadius;

	// Hook
	UPROPERTY(VisibleAnywhere)
		FOnTimelineFloat TimelineProgress;

	UPROPERTY(VisibleAnywhere)
		FTimeline T_Hooked;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcess = "true"))
		UCurveFloat* HookCurve;

	FOnTimelineEvent OnT_FinishHook;

	// Pull
	UPROPERTY(VisibleAnywhere)
		FOnTimelineFloat TimelineProgressPull;

	UPROPERTY(VisibleAnywhere)
		FTimeline T_Pull;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcess = "true"))
		UCurveFloat* PullCurve;

	FOnTimelineEvent OnT_FinishPull;


	FTimerHandle TimerHandel;
	FVector OwnerLoaction;
	FVector HitActorLocation;
	bool bHasHookLocation;
	bool bHasPulled;

	AActor* hitActor;


private:
	UFUNCTION(BlueprintCallable)
		bool TraceForPhysicsBodiesLine(class UCameraComponent* CameraComp, FHitResult& HitActor, UPrimitiveComponent*& HitComponent);

	// Hook Timelines
	UFUNCTION()
		void T_HookProgress(float value);

	UFUNCTION()
		void T_HookFinish();

	// Pull Times
	UFUNCTION()
		void T_PullProgress(float value);

	UFUNCTION()
		void T_PullFinish();

	/* Checks to if the player is close enoght to hook towards an hookable object.
	 * It also checks what direction the player facing.
	 */
	UFUNCTION()
		bool HookDirectionCheck(FHitResult HitResult);

public:
	UPROPERTY(EditAnywhere)
		float hookDelay;

public:
	UFUNCTION(BlueprintCallable)
		void HookTowards();

	UFUNCTION(BlueprintCallable)
		void PullTowards(AActor* Actor);
		
};
