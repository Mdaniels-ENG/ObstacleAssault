// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//Move Platform forwards
		//Get current location
	FVector CurrentLocation = GetActorLocation();
		//Add vector to that location
	CurrentLocation += PlatformVelocity * DeltaTime;
		//Set location
	SetActorLocation(CurrentLocation);
	//Send platform back if gone too far
		//Check how we've moved.
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		//Reverse direction of motion if gone too far
	if(DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("Platform over shot by %fcm"), OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity *= -1;
	}
}