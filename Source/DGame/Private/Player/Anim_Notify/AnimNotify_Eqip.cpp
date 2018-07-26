#include "AnimNotify_Eqip.h"
#include "DGame.h"

bool UAnimNotify_Eqip::Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	
	if(!m_pawn) { m_pawn = Cast<ADCharacter>(MeshComp->GetOwner()); }
	if(!m_pawn) {
		UDUtility::debug_out("no character");
		return false;
	}
	m_pawn->change_sword_place("sword_1");
	m_pawn->change_shield_place("shield_1");
	return true;
}


