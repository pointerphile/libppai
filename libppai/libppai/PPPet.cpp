#include "PPPet.h"

PP::PPPet::PPPet(int iPosition) {
	m_iPosition = iPosition;
	m_ObjectType = PP::PPObjectType::Pet;
	SetPet();
	std::cout << "Pet is created at x : " << m_iPosition << std::endl;
}
PP::PPPet::~PPPet() {
	std::cout << "Pet is dead" << std::endl;
}

void PP::PPPet::SetPet() {
	m_BT.SetPet(this);
}
