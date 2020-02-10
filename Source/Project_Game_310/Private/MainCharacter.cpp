// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/InputComponent.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

//moving front to back
void AMainCharacter::MoveForward(float Value)
{
	//if button is pressed
	if (Value != 0.0f)
	{
		//pissing around with this (kacper)
		/*const FVector forward = AMainCharacter::GetActorForwardVector();
		const FRotator YawRotation(0, forward.Z, 0);
		const FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);*/

		const FVector direction = AMainCharacter::GetActorForwardVector();
		//moving character
		AddMovementInput(direction, Value);

	}
}

//moving side to side function
void AMainCharacter::MoveRight(float Value)
{
	//if button is pressed
	if (Value != 0.0f)
	{

		//pissing around with this (kacper)
		/*const FVector forward = AMainCharacter::GetActorForwardVector();
		const FRotator YawRotation(0, forward.Z, 0);

		const FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
*/

		const FVector direction = AMainCharacter::GetActorRightVector();
	
		//moving character
		AddMovementInput(direction, Value);

	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//only enables a single jump (calls premade function)
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//calls functions to move character
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
}

