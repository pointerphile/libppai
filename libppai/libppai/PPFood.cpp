#include "PPFood.h"

PP::PPFood::PPFood(int iPosition, int iQuantity) {
	int m_iPosition = iPosition;
	int m_iQuantity = iQuantity;
	m_ObjectType = PP::PPObjectType::Food;
	std::cout << m_iQuantity << " of Food is created at x : " << m_iPosition << std::endl;
}
PP::PPFood::~PPFood() {
	std::cout << "Food is destroyed" << std::endl;
}
