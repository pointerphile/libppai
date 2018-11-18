#include "PPObjectManager.h"

PP::PPObjectManager::PPObjectManager() {}
PP::PPObjectManager::~PPObjectManager() {}

void* PP::PPObjectManager::push_back_Pet(int iPosition) {
	PP::PPPet* pPet = new PP::PPPet(iPosition);
	m_listpObject.push_back(pPet);

	return pPet;
}

void * PP::PPObjectManager::push_back_Food(int iPosition, int iQuantity)
{
	PP::PPFood* pFood = new PP::PPFood(iPosition, iQuantity);
	m_listpObject.push_back(pFood);

	return pFood;
}

bool PP::PPObjectManager::CheckElement(PP::PPObject * pObject) {
	std::list<PP::PPObject*>::iterator iterFind;
	iterFind = std::find(m_listpObject.begin(), m_listpObject.end(), pObject);
	if (iterFind != m_listpObject.end()) {
		return true;
	}
	else {
		return false;
	}
}

void PP::PPObjectManager::erase(PP::PPObject * pObject) {
	std::list<PP::PPObject*>::iterator iterErase;
	iterErase = std::find(m_listpObject.begin(), m_listpObject.end(), pObject);
	if (iterErase != m_listpObject.end()) {
		delete pObject;
		m_listpObject.erase(iterErase);
		pObject = nullptr;
	}
}
