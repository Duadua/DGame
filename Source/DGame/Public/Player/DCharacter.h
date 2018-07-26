#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DCharacter.generated.h"

UCLASS(Abstract)
class DGAME_API ADCharacter : public ACharacter 
{
	GENERATED_UCLASS_BODY()


protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginDestroy() override;

	/** spawn inventory, setup initial variables */
	virtual void PostInitializeComponents() override;

	/** cleanup inventory */
	virtual void Destroyed() override;

	/** update mesh for first person view */
	virtual void PawnClientRestart() override;

	/** [server] perform PlayerState related setup */
	virtual void PossessedBy(class AController* C) override;

	/** [client] perform PlayerState related setup */
	virtual void OnRep_PlayerState() override;

	/** [server] called to determine if we should pause replication this actor to a specific player */
	virtual bool IsReplicationPausedForConnection(const FNetViewer& ConnectionOwnerNetViewer) override;

	/** [client] called when replication is paused for this actor */
	virtual void OnReplicationPausedChanged(bool bIsReplicationPaused) override;

public:
	// 相机arm
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* m_camera_boom;
	//相机
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* m_camera_component;

	// 鼠标贴花
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* m_cursor_to_world;

	// 武器
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* m_sword;

	// 盾牌
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* m_shield;

	UPROPERTY(EditAnywhere, Category = "Eye Control", meta = (AllowPrivateAccess = "true"))
	float m_rate_turn;
	UPROPERTY(EditAnywhere, Category = "Eye Control", meta = (AllowPrivateAccess = "true"))
	float m_rate_lookup;
	UPROPERTY(EditAnywhere, Category = "Eye Control", meta = (AllowPrivateAccess = "true"))
	float m_scale_rate;
	UPROPERTY(EditAnywhere, Category = "Eye Control", meta = (AllowPrivateAccess = "true"))
	float m_scale_min;
	UPROPERTY(EditAnywhere, Category = "Eye Control", meta = (AllowPrivateAccess = "true"))
	float m_scale_max;

	void init_body();						// 初始化 本身一些属性  
	void init_movement();					// 设置 移动组件 的属性 
	void init_camera();						// 初始化相机       
	void init_cursor();						// 初始化光标       
	void init_sword();						// 初始化武器       
	void init_shield();						// 初始化盾牌       

	

	// 移动相关
	void move_forward(float value);
	void move_right(float value);
	void turn_rate(float value);
	void lookup_rate(float value);
	void scale(float value);

	// 视角相关
	class ADPlayerController* get_controller();

	//切换装备状态
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "eqip")
	uint32 m_b_eqip : 1;
	UFUNCTION(BlueprintCallable)
	void change_sword_place(FName n);		// 改变武器位置
	UFUNCTION(BlueprintCallable)
	void change_shield_place(FName n);		// 改变盾牌位置

	void on_eqip_toggle();
	UFUNCTION(reliable, server, WithValidation)
	void server_on_eqip_toggle();

	// 技能1
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "attack")
	uint32 m_b_attack_1 : 1;
	void on_attack_1();
	UFUNCTION(reliable, server, WithValidation)
	void server_on_attack_1();
};
