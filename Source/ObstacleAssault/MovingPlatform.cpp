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

	FString MyString = "My String Value";

	UE_LOG(LogTemp, Display, TEXT("Here's My String: %s"), *MyString);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		//Calcuate the exact maximum distance it is allowed to move
		//And reset startlocation to that point
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		//Reverse movement
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector currentLocation = GetActorLocation();
		currentLocation = currentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(currentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("%s Rotating..."), *GetName());
	FRotator Currentrotation = GetActorRotation();
	AddActorLocalRotation(RotationVelocity*DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}