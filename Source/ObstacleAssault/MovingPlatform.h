// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	int32 IntA = 0;

	UPROPERTY(EditAnywhere)
	int32 IntB = 0;
	
	UPROPERTY(EditAnywhere)
	int32 APlusBInt = 0;

	UPROPERTY(EditAnywhere)
	float FloatA = 0.0;

	UPROPERTY(EditAnywhere)
	float FloatB = 0.0;
	
	UPROPERTY(EditAnywhere)
	float APlusBFloat = 0.0;

	UPROPERTY(EditAnywhere)
	float MyFloat = 0.0001;

	UPROPERTY(EditAnywhere)
	bool MyBool = true;

};