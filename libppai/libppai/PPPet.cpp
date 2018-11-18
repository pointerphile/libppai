#include "PPPet.h"

PP::PPPet::PPPet() {}
PP::PPPet::~PPPet() {
	std::cout << "Pet is dead" << std::endl;
}

void PP::PPPet::SetPPPet(int iPosition) {
	m_iPosition = iPosition;
	m_ObjectType = PP::PPObjectType::Pet;
	std::cout << "Pet is created at x : " << m_iPosition << std::endl;
}
