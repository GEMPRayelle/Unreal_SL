// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

//개발자에게 Actor는 C++ Actor를 말하는거임

//블루 프린트 액터 클래스가 GameOjbect, Prefab 둘다 비슷하다
//C++ 액터는 그냥 다른거라고 생각, 물론 C++ 액터를 블루프린트로 뽑아낸다는 관점에선 GameObject와 비슷함

// Sets default values
AMyActor::AMyActor() //UnityEngine Awake()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() //UnityEngine Start()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime) //UnityEngine Update()
{
	Super::Tick(DeltaTime);

}

void AMyActor::Instantiate()
{
	FActorSpawnParameters Params = {};

	Params.Owner = this;
	Params.Name = FName(TEXT("MyActorInstance"));

	GetWorld()->SpawnActor<AMyActor>(AMyActor::StaticClass(), FVector3d(0.0f,0.0f,0.0f), FRotator(0.0f, 0.0f, 0.0f), Params);
}

