// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

//개발자에게 Actor는 C++ Actor를 말하는거임

//블루 프린트 액터 클래스가 GameObject, Prefab 둘다 비슷하다
//C++ 액터는 그냥 다른거라고 생각, 물론 C++ 액터를 블루프린트로 뽑아낸다는 관점에선 GameObject와 비슷함

AMyActor::AMyActor() //Constructor
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//C++ 액터에 컴포넌트 추가하는 코드, 루트 컴포넌트에 씬컴포넌트 생성 후 저장
	//루트 컴포넌트는 엔진단에서 기본적으로 추가해줘서 헤더에 선언 안해도 됨
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	//RootComponent : 유니티의 transform.root랑 비슷함, 루트가 있어야 이후 컴포넌트 좌표를 전체적으로 옮길 수 있음
	//이게 있어야지 C++ 클래스 액터를 레벨에 배치할때 이동할 수 있음
	
	Root = RootComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root); //부모 지정

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereMesh.Succeeded())
	{
		Mesh->SetStaticMesh(SphereMesh.Object);
	}

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

void AMyActor::PrintLog()
{
	UE_LOG(LogTemp, Warning, TEXT("Function Call."), Value);
}
