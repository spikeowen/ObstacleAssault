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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Moving")
	FVector PlatformVelocity = FVector (100, 0, 0 );
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Moving")
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rotation")
	FRotator RotationVelocity;

	FVector StartLocation;

private:	
	

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};








/*	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	int32 InputA = 4;

	UPROPERTY(EditAnywhere)
	int32 InputB = 5;

	UPROPERTY(EditAnywhere)
	int32 APlusB = 0;

	UPROPERTY(EditAnywhere)
	float MyFloat = 5.99;

	UPROPERTY(EditAnywhere)
	float FloatInputA = 3.5;

	UPROPERTY(EditAnywhere)
	float FloatInputB = 6.5;

	UPROPERTY(EditAnywhere)
	float FloatAPlusB = 0;

	UPROPERTY(EditAnywhere)
	bool MyBool = true;
*/