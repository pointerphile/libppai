#include "PPObjectManager.h"

PP::PPObjectManager::PPObjectManager() {}
PP::PPObjectManager::~PPObjectManager() {}

//void* PP::PPObjectManager::push_back_Pet(int iPosition) {
//	PP::PPPet* pPet = new PP::PPPet;
//	pPet->SetPPPet(iPosition);
//	m_listpObject.push_back(pPet);
//
//	return pPet;
//}

PP::PPHandle PP::PPObjectManager::push_back_Pet_m(int iPosition) {
	PP::PPPet* pPet = new PP::PPPet;
	pPet->SetPPPet(iPosition);
	m_mapObject.insert(std::pair<PP::PPHandle, PP::PPObject*>(++m_iID, pPet));

	return m_iID;
}

//void * PP::PPObjectManager::push_back_Food(int iPosition, int iQuantity) {
//	PP::PPFood* pFood = new PP::PPFood;
//	pFood->SetPPFood(iPosition, iQuantity);
//	m_listpObject.push_back((PP::PPObject*)pFood);
//	m_mapObject.insert(std::pair<PP::PPHandle, PP::PPObject*>(++m_iID, pFood));
//
//	return pFood;
//}

PP::PPHandle PP::PPObjectManager::push_back_Food_m(int iPosition, int iQuantity) {
	PP::PPFood* pFood = new PP::PPFood;
	pFood->SetPPFood(iPosition, iQuantity);
	m_listpObject.push_back((PP::PPObject*)pFood);
	m_mapObject.insert(std::pair<PP::PPHandle, PP::PPObject*>(++m_iID, pFood));

	return m_iID;
}

//bool PP::PPObjectManager::CheckElement(PP::PPObject * pObject) {
//	std::list<PP::PPObject*>::iterator iterFind;
//	iterFind = std::find(m_listpObject.begin(), m_listpObject.end(), pObject);
//	if (iterFind != m_listpObject.end()) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

bool PP::PPObjectManager::CheckElement_m(PP::PPHandle Handle)
{
	std::map<PP::PPHandle, PP::PPObject*>::iterator iterFind;
	iterFind = m_mapObject.find(Handle);

	if (iterFind != m_mapObject.end()) {
		return true;
	}
	else {
		return false;
	}
}

//void PP::PPObjectManager::erase(PP::PPObject * pObject) {
//	std::list<PP::PPObject*>::iterator iterErase;
//	iterErase = std::find(m_listpObject.begin(), m_listpObject.end(), pObject);
//	if (iterErase != m_listpObject.end()) {
//		delete pObject;
//		m_listpObject.erase(iterErase);
//		pObject = nullptr;
//	}
//}

void PP::PPObjectManager::erase_m(PP::PPHandle Handle) {
	std::map<PP::PPHandle, PP::PPObject*>::iterator iterErase;
	iterErase = m_mapObject.find(Handle);
	if (iterErase != m_mapObject.end()) {
		delete iterErase->second;
		iterErase->second = nullptr;
		m_mapObject.erase(iterErase);
	}
}

void * PP::PPObjectManager::GetpObject(PP::PPHandle Handle)
{
	std::map<PP::PPHandle, PP::PPObject*>::iterator iterFind;
	iterFind = m_mapObject.find(Handle);

	if (iterFind != m_mapObject.end()) {
		return iterFind->second;
	}
	else {
		return nullptr;
	}
}
