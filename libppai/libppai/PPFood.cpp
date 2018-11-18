#include "PPFood.h"

PP::PPFood::PPFood() {}
PP::PPFood::~PPFood() {
	std::cout << "Food is destroyed" << std::endl;
}

void PP::PPFood::SetPPFood(int iPosition, int iQuantity)
{
	m_iPosition = iPosition;
	m_iQuantity = iQuantity;
	m_ObjectType = PP::PPObjectType::Food;
	std::cout << m_iQuantity << " of Food is created at x : " << m_iPosition << std::endl;
}

