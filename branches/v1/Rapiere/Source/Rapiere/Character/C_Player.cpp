// Fill out your copyright notice in the Description page of Project Settings.

#include "Rapiere.h"
#include "C_Player.h"


// Sets default values
AC_Player::AC_Player()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	BaseTurnRate = 45.f;
	BaseLookupRate=45.f;
	//To do in the editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshTower(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (SkeletalMeshTower.Object) {
		GetMesh()->SetSkeletalMesh(SkeletalMeshTower.Object);
	}
	//Setup Mesh with mesh coming from Editor
	if(GetMesh()!=NULL){
		GetMesh()->SetOnlyOwnerSee(true);
		GetMesh()->bCastDynamicShadow = false;
		GetMesh()->CastShadow = false;
		GetMesh()->SetupAttachment(GetCapsuleComponent());
		
		//Setup Camera attaching it to head socket
		FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
		FirstPersonCamera->SetupAttachment(GetMesh(),TEXT("sock_head"));
		FirstPersonCamera->bUsePawnControlRotation = true;
		//Setup weapon to hand Socket
		PC_Weapon = CreateDefaultSubobject<UPC_PlayerWeapon>(TEXT("Weapon"));
		PC_Weapon->SetupAttachment(GetMesh(),TEXT("sock_hand_r"));
	}
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	GetCharacterMovement()->AirControl = 1;
}

// Called when the game starts or when spawned
void AC_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (BisFire) {
		PC_Weapon->DelayFire(HasFire, 0.1f);
		HasFire = true;
	}
}

// Called to bind functionality to input
void AC_Player::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AC_Player::StartFire);
	InputComponent->BindAction("Fire", IE_Released, this, &AC_Player::StopFire);
	if (!IsJumpProvidingForce())
	{
		InputComponent->BindAction("Jump", IE_Pressed, this, &AC_Player::StartJump);
	}
	InputComponent->BindAction("Jump", IE_Released, this, &AC_Player::StopJump);

	InputComponent->BindAxis("MoveForward", this, &AC_Player::MoveForward);
	InputComponent->BindAxis("MoveLeftRight", this, &AC_Player::MoveLeftRight);

	InputComponent->BindAxis("Turn", this, &AC_Player::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &AC_Player::LookUpAtRate);

}
//to fly, put clearJumpInput in IE_Repeat event
void AC_Player::StopJump()
{
	bPressedJump=false;
}

void AC_Player::StartJump()
{
	bPressedJump = true;
}

void AC_Player::StartFire()
{
	BisFire = true;
}

void AC_Player::StopFire()
{
	BisFire = false;
	HasFire = false;
	GetWorld()->GetTimerManager().ClearTimer(PC_Weapon->HandleTime);
}

void AC_Player::MoveForward(float value)
{
	if (value != 0.0f)
	{

		AddMovementInput(GetActorForwardVector(), value);
	}
}

void AC_Player::MoveLeftRight(float value)
{
	if (value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void AC_Player::TurnAtRate(float value)
{
	AddControllerYawInput(value*BaseTurnRate*GetWorld()->GetDeltaSeconds());
}

void AC_Player::LookUpAtRate(float value)
{
	AddControllerPitchInput(value*BaseLookupRate*GetWorld()->GetDeltaSeconds());
}

