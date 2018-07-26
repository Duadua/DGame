#include "AnimNotify_UnEqip.h"
#include "DGame.h"

UAnimNotify_UnEqip::UAnimNotify_UnEqip(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

bool UAnimNotify_UnEqip::Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if(!m_pawn) {
		m_pawn = Cast<ADCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	}
	if(!m_pawn) {
		UDUtility::debug_out("no character");
		return false;
	}

	m_pawn->change_sword_place("sword_2");
	m_pawn->change_shield_place("shield_2");
	return true;

}