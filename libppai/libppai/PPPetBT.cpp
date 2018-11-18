#include "PPPetBT.h"
#include "PPObjectManager.h"

PP::PPPetBT::PPPetBT() {
	m_pRoot = new PP::Sequence;
	m_pSequence0 = new PP::Sequence;
	m_pSequence1 = new PP::Sequence;
	m_pSelector0 = new PP::Selector;
	m_pCheckTarget = new PP::CheckTarget(this->m_pTargetFood);
	m_pActionSearchFood = new PP::ActionSearchFood(this->m_pPet);
	m_ActionChaseFood = new PP::ActionChaseFood(this->m_pPet, this->m_pTargetFood);
	m_ActionEatFood = new PP::ActionEatFood(this->m_pTargetFood);

	m_pRoot->AddChild(m_pSequence0);
	m_pSequence0->AddChild(m_pSelector0);
	m_pSequence0->AddChild(m_pSequence1);
	m_pSelector0->AddChild(m_pCheckTarget);
	m_pSelector0->AddChild(m_pActionSearchFood);

}
PP::PPPetBT::~PPPetBT() {}

void PP::PPPetBT::SetPet(PP::PPObject *pObject) {
	m_pPet = pObject;
	std::cout << "BT: Standby." << std::endl;
}

bool PP::CheckTarget::Run() {
	if (this->m_pTargetFood == nullptr) {
		std::cout << "BT: 타겟이 없음. false" << std::endl;
		return false;
	}
	else {
		bool isTargetValid = PP::PPObjectManager::GetInstance().CheckElement(m_pTargetFood);
		if (isTargetValid) {
			std::cout << "BT: 타겟은 매니저에 존재함. true" << std::endl;
			return isTargetValid;
		}
		else {
			std::cout << "BT: 타겟은 매니저에 존재하지 않음. false" << std::endl;
			return isTargetValid;
		}
	}
}

bool PP::ActionSearchFood::Run() {
	for (PP::PPObject* pObject : PP::PPObjectManager::GetInstance().m_listpObject) {
		if (pObject->m_ObjectType == PP::PPObjectType::Food) {
			std::cout << "FOOD!" << std::endl;
		}
	}

	return false;
}

bool PP::ActionChaseFood::Run()
{
	return false;
}

bool PP::ActionEatFood::Run()
{
	return false;
}