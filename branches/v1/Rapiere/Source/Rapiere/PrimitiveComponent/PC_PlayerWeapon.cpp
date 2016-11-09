// Fill out your copyright notice in the Description page of Project Settings.

#include "Rapiere.h"
#include "PC_PlayerWeapon.h"
void UPC_PlayerWeapon::DelayFire(bool isfiring, float delay) {
	if (!isfiring) {
		DelegateTime.BindUFunction(this, FName("Fire"));
		GetWorld()->GetTimerManager().SetTimer(HandleTime, DelegateTime, delay, true);
	}
}
void UPC_PlayerWeapon::Fire()
{
	Projectile = GetWorld()->SpawnActor<AA_Projectile>(AA_Projectile::StaticClass(), UM_WeaponMesh->GetSocketTransform("Barrel0"));
}

UPC_PlayerWeapon::UPC_PlayerWeapon()
{
	//Create WeaponMesh?
	UM_WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshWepon"));
	HandleTime = FTimerHandle();
	DelegateTime = FTimerDynamicDelegate();
	//To do in the editor
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshTower(TEXT("StaticMesh'/Game/Geometries/Meshes/ProtoGun.ProtoGun'"));
	if (StaticMeshTower.Object) {
		UM_WeaponMesh->SetStaticMesh(StaticMeshTower.Object);
	}
	//Setup Weapon Mesh
	if(UM_WeaponMesh!=NULL){
		UM_WeaponMesh->SetupAttachment(this);
	}
	}

void UPC_PlayerWeapon::BeginPlay()
{
}
