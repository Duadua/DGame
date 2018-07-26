#include "DCharacter.h"
#include "DCharacterMovement.h"
#include "DGame.h"

ADCharacter::ADCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UDCharacterMovement>(ACharacter::CharacterMovementComponentName))
{
	init_body();											// ��ʼ�� ����һЩ����
	init_movement();										// ��ʼ�� �ƶ����
	init_camera();											// ��ʼ�� ���
	init_cursor();											// ��ʼ�� �������
	init_sword();											// ��ʼ�� ����
	init_shield();											// ��ʼ�� ����


}

// Called when the game starts or when spawned
void ADCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward",            this, &ADCharacter::move_forward);   
	PlayerInputComponent->BindAxis("MoveRight",              this, &ADCharacter::move_right);     
	PlayerInputComponent->BindAxis("TurnRate",               this, &ADCharacter::turn_rate);      
	PlayerInputComponent->BindAxis("LookUpRate",             this, &ADCharacter::lookup_rate);    
	PlayerInputComponent->BindAxis("Scale",                  this, &ADCharacter::scale);          

	PlayerInputComponent->BindAction("Jump", IE_Pressed,     this, &ADCharacter::Jump);           
	PlayerInputComponent->BindAction("Jump", IE_Released,    this, &ADCharacter::StopJumping);    

	PlayerInputComponent->BindAction("Eqip", IE_Pressed,     this, &ADCharacter::on_eqip_toggle); 
	
	PlayerInputComponent->BindAction("Attack_1", IE_Pressed, this, &ADCharacter::on_attack_1);    

}


void ADCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ADCharacter::BeginDestroy()
{
	Super::BeginDestroy();
}

void ADCharacter::Destroyed()
{
	Super::Destroyed();
}

void ADCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();
}

void ADCharacter::PossessedBy(class AController* C)
{
	Super::PossessedBy(C);
}

void ADCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

bool ADCharacter::IsReplicationPausedForConnection(const FNetViewer& ConnectionOwnerNetViewer)
{
	return Super::IsReplicationPausedForConnection(ConnectionOwnerNetViewer);
}

void ADCharacter::OnReplicationPausedChanged(bool bIsReplicationPaused)
{
	Super::OnReplicationPausedChanged(bIsReplicationPaused);
}



// ��ʼ�� ����һЩ����
void ADCharacter::init_body() {
	bReplicates = true;
	// Tick ����
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);			// ��ʼ���������С

																	// ����������Controller�ƶ�
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// ���� mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("/Game/assets/Character/SK_Mannequin"));
	if(mesh.Succeeded()) GetMesh()->SetSkeletalMesh(mesh.Object, true);
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -97.5f), FRotator(0.f, -90.f, 0.f).Quaternion());

	m_rate_turn = 45.f;
	m_rate_lookup = 45.f;

	m_scale_rate = 100.f;
	m_scale_min = 200.f;
	m_scale_max = 5000.f;

	m_b_eqip = true;

	m_b_attack_1 = false;

}

// ���� �ƶ���� ������
void ADCharacter::init_movement() {
	GetCharacterMovement()->bOrientRotationToMovement = true;				// �� �ƶ���� Ϊ�����ƶ�����
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);		// ��ת�ٶ�
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->bConstrainToPlane = false;						// Լ����������
	GetCharacterMovement()->bSnapToPlaneAtStart = false;					// һ��ʼ�ͷŵ�������

}
// ��ʼ�����
void ADCharacter::init_camera() {
	// ��ʼ����� arm
	m_camera_boom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	m_camera_boom->SetupAttachment(RootComponent);
	m_camera_boom->TargetArmLength = 600.f;								// ��ʼ�۳�
	m_camera_boom->RelativeRotation = FRotator(-45.f, 0.f, 0.f);	// ��ʼ�Ƕ�
	m_camera_boom->bDoCollisionTest = false;						// ��ֹ��ײ
	m_camera_boom->bAbsoluteRotation = true;						// �����ƶ���ʱ�����arm���ƶ�
	m_camera_boom->bUsePawnControlRotation = true;						// ��PlayerController ��ת

																		// ��ʼ�����
	m_camera_component = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	m_camera_component->SetupAttachment(m_camera_boom, USpringArmComponent::SocketName);
	m_camera_component->bUsePawnControlRotation = false;					// �������arm�ƶ�
}
// ��ʼ�����
void ADCharacter::init_cursor() {
	m_cursor_to_world = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	m_cursor_to_world->SetupAttachment(RootComponent);
	// ����������ʽ
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/Assets/Cursor/M_Cursor_Decal.M_Cursor_Decal'"));
	if(DecalMaterialAsset.Succeeded()) m_cursor_to_world->SetDecalMaterial(DecalMaterialAsset.Object);

	m_cursor_to_world->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	m_cursor_to_world->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	m_cursor_to_world->SetVisibility(false);
}
// ��ʼ������
void ADCharacter::init_sword() {
	m_sword = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SwordComponent"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> sword_mesh(TEXT("/Game/Assets/Weapon/Sword"));
	if(sword_mesh.Succeeded()) m_sword->SetSkeletalMesh(sword_mesh.Object, true);
	change_sword_place("sword_2");
}

// ��ʼ������
void ADCharacter::init_shield() {
	m_shield = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShieldComponent"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> shield_mesh(TEXT("/Game/Assets/Weapon/Shield"));
	if(shield_mesh.Succeeded()) m_shield->SetSkeletalMesh(shield_mesh.Object, true);
	change_shield_place("shield_2");
}

// �ı�����λ��
void ADCharacter::change_sword_place(FName name) {
	m_sword->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, name);
}
// �ı����λ��
void ADCharacter::change_shield_place(FName name) {
	m_shield->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, name);
}

void ADCharacter::move_forward(float value)
{
	if (m_b_attack_1) return;
	if(!Controller || value == 0.f) return;
	// Limit pitch when walking or falling
	//const bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
	//const FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
	const FRotator rotation = GetControlRotation();
	const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value);
}
void ADCharacter::move_right(float value)
{
	if (m_b_attack_1) return;
	if(value == 0.f) return;
	const FRotator rotation = GetControlRotation();
	const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);
}
void ADCharacter::turn_rate(float value)
{
	if(get_controller()->m_b_can_rotate == false) return;
	AddControllerYawInput(value * m_rate_turn * GetWorld()->GetDeltaSeconds());
}
void ADCharacter::lookup_rate(float value)
{
	if(get_controller()->m_b_can_rotate == false) return;
	AddControllerPitchInput(value * m_rate_lookup * GetWorld()->GetDeltaSeconds());
}
void ADCharacter::scale(float value)
{
	float val = m_camera_boom->TargetArmLength + value * m_scale_rate; 
	m_camera_boom->TargetArmLength = FMath::Clamp(val, m_scale_min, m_scale_max);
}

ADPlayerController* ADCharacter::get_controller() { return Cast<ADPlayerController>(Controller); }

void ADCharacter::on_eqip_toggle() { 
	server_on_eqip_toggle();
//	if (Role == ROLE_Authority) { m_b_eqip = !m_b_eqip; }

}

bool ADCharacter::server_on_eqip_toggle_Validate()
{
	return true;
}

void ADCharacter::server_on_eqip_toggle_Implementation()
{
	if (Role == ROLE_Authority) { m_b_eqip = !m_b_eqip; }
}


void ADCharacter::on_attack_1()
{
	server_on_attack_1();
}

bool ADCharacter::server_on_attack_1_Validate()
{
	return true;
}

void ADCharacter::server_on_attack_1_Implementation()
{
	if (Role == ROLE_Authority) { if (!m_b_attack_1 && m_b_eqip) m_b_attack_1 = true; }
}

void ADCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADCharacter, m_b_eqip);
	DOREPLIFETIME(ADCharacter, m_b_attack_1);
}




