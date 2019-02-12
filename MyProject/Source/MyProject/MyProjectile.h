// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyProjectile.generated.h"
class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class MYPROJECT_API AMyProjectile : public AActor
{
	GENERATED_BODY()
public:
	AMyProjectile();
	void FireInDirection(const FVector& ShootDirection);
private:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* CollisionComponent = nullptr;
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;
};
