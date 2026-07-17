// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class RAYELLESL_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public: 
	// Sets default values for this actor's properties
	AMyActor();

	//루트 컴포넌트
	UPROPERTY(VisibleAnywhere) USceneComponent* Root;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Instantiate();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IsntGannaUse")
	float Value;

	UFUNCTION(BlueprintCallable, Category="IsntGannaUse")
	void PrintLog();
};
