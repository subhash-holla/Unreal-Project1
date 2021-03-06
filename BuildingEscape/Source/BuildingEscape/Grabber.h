// Copyright Subhash 2018.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FTwoVectors GetLineTracePoints() const;

private:
	//How far ahead of the player can we reach
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	
	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab box in reach
	void Grab();
	
	// Called when grab is released
	void Release();

	//Find attached physics handle
	void FindPhysicsHandleComponent();

	//Setup (assumed) attached input component
	void SetupInputComponent();

	//Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;
};
