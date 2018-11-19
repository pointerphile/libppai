#include "PPPetBT.h"
#include "PPObjectManager.h"

PP::PPPetBT::PPPetBT(PP::PPObject *pObject) {
	m_pPet = pObject;
	m_pRoot = new PP::Sequence;
	m_pSequence0 = new PP::Sequence;
	m_pSequence1 = new PP::Sequence;
	m_pSelector0 = new PP::Selector;
	m_pCheckTarget = new PP::CheckTarget(&m_hTargetFood);
	m_pActionSearchFood = new PP::ActionSearchFood(&m_pPet, &m_hTargetFood, &m_pTargetFood);
	m_ActionChaseFood = new PP::ActionChaseFood(&m_pPet, &m_pTargetFood);
	m_ActionEatFood = new PP::ActionEatFood(&m_pPet, &m_hTargetFood, &m_pTargetFood);

	m_pRoot->AddChild(m_pSequence0);
	m_pSequence0->AddChild(m_pSelector0);
	m_pSequence0->AddChild(m_pSequence1);
	m_pSelector0->AddChild(m_pCheckTarget);
	m_pSelector0->AddChild(m_pActionSearchFood);

	m_pSequence1->AddChild(m_ActionChaseFood);
	m_pSequence1->AddChild(m_ActionEatFood);
}
PP::PPPetBT::~PPPetBT() {}

bool PP::CheckTarget::Run() {
	if (m_phTargetFood == 0) {
		std::cout << "BT: 타겟이 없음. false" << std::endl;
		return false;
	}
	else {
		bool isTargetValid = PP::PPObjectManager::GetInstance().CheckElement_m(*m_phTargetFood);
		if (isTargetValid) {
			std::cout << "BT: 타겟은 매니저에 존재함. true" << std::endl;
			//std::cout << "타겟의 위치 : " << (*m_pTargetFood)->m_iPosition << std::endl;
			return isTargetValid;
		}
		else {
			std::cout << "BT: 타겟은 매니저에 존재하지 않음. false" << std::endl;
			return isTargetValid;
		}
	}
}

bool PP::ActionSearchFood::Run() {
	PP::PPHandle handle = 0;
	PP::PPObject* pFoodTemp = nullptr;
	for (auto& pObject : PP::PPObjectManager::GetInstance().m_mapObject) {
		if (pObject.second->m_ObjectType == PP::PPObjectType::Food) {
			std::cout << "FOOD! " << abs(((PP::PPFood*)pObject.second)->m_iPosition - (*m_pPet)->m_iPosition) << " points far from me!" << std::endl;
			if (pFoodTemp == nullptr) {
				handle = pObject.first;
				pFoodTemp = pObject.second;
			}
			else {
				if (
					abs(((PP::PPFood*)pFoodTemp)->m_iPosition - (*m_pPet)->m_iPosition)
					 >= abs(((PP::PPFood*)pObject.second)->m_iPosition - (*m_pPet)->m_iPosition)
				)
				{
					handle = pObject.first;
					pFoodTemp = pObject.second;
				}
			}
			*m_phTargetFood = handle;
			*m_pTargetFood = (PP::PPFood*)pFoodTemp;
		}
	}
	if (*m_pTargetFood == nullptr) {
		std::cout << "타게팅 실패, 타겟은 맵 상에 없다." << std::endl;
		return false;
	}
	else {
		std::cout << "타게팅 성공, 새 타겟의 위치는 " << (*m_pTargetFood)->m_iPosition << std::endl;
		return true;
	}
}

bool PP::ActionChaseFood::Run() {
	if ((*m_pPet)->m_iPosition > (*m_pTargetFood)->m_iPosition) {
		(*m_pPet)->m_iPosition--;
		std::cout << "-1 만큼 이동" << std::endl;
	}
	else if ((*m_pPet)->m_iPosition < (*m_pTargetFood)->m_iPosition) {
		(*m_pPet)->m_iPosition++;
		std::cout << "+1 만큼 이동" << std::endl;
	}
	return true;
}

bool PP::ActionEatFood::Run() {
	std::cout << "먹기실시" << std::endl;
	if ((*m_pPet)->m_iPosition != (*m_pTargetFood)->m_iPosition) {
		std::cout << "먹이와 위치가 일치하지 않다." << std::endl;
		return false;
	}
	else if((*m_pPet)->m_iPosition == (*m_pTargetFood)->m_iPosition) {
		if ((*m_pTargetFood)->m_iQuantity > 1) {
			(*m_pTargetFood)->m_iQuantity--;
			std::cout << "먹이를 1 만큼 먹었다." << std::endl;
			return true;
		}
		else if ((*m_pTargetFood)->m_iQuantity == 1) {
			(*m_pTargetFood)->m_iQuantity--;
			std::cout << "먹이를 1 만큼 먹었다." << std::endl;
			PP::PPObjectManager::GetInstance().erase_m(*m_phTargetFood);
			*m_phTargetFood = 0;
			*m_pTargetFood = nullptr;
			return true;
		}
	}
}