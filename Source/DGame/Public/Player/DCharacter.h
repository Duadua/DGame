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
	// ���arm
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* m_camera_boom;
	//���
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* m_camera_component;

	// �������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* m_cursor_to_world;

	// ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* m_sword;

	// ����
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

	void init_body();						// ��ʼ�� ����һЩ����  
	void init_movement();					// ���� �ƶ���� ������ 
	void init_camera();						// ��ʼ�����       
	void init_cursor();						// ��ʼ�����       
	void init_sword();						// ��ʼ������       
	void init_shield();						// ��ʼ������       

	

	// �ƶ����
	void move_forward(float value);
	void move_right(float value);
	void turn_rate(float value);
	void lookup_rate(float value);
	void scale(float value);

	// �ӽ����
	class ADPlayerController* get_controller();

	//�л�װ��״̬
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "eqip")
	uint32 m_b_eqip : 1;
	UFUNCTION(BlueprintCallable)
	void change_sword_place(FName n);		// �ı�����λ��
	UFUNCTION(BlueprintCallable)
	void change_shield_place(FName n);		// �ı����λ��

	void on_eqip_toggle();
	UFUNCTION(reliable, server, WithValidation)
	void server_on_eqip_toggle();

	// ����1
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "attack")
	uint32 m_b_attack_1 : 1;
	void on_attack_1();
	UFUNCTION(reliable, server, WithValidation)
	void server_on_attack_1();
};
