// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UStaticMeshComponent;

UCLASS()
class PROJECT_GAME_310_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	//enable setting a static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	UStaticMeshComponent* meshComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//movement functions
	void MoveForward(float Value);
	void MoveRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
