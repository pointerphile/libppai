#include "PPPetBT.h"

PP::PPPetBT::PPPetBT() {}
PP::PPPetBT::~PPPetBT() {}

PP::FoodStatus::FoodStatus(int iPosition, int iQuantity) : m_iPosition(iPosition), m_iQuantity(iQuantity)
{
	std::wcout << L"��� ������" << std::endl;
}

PP::FoodStatus::~FoodStatus()
{
	std::wcout << L"��� �Ҹ��" << std::endl;
}
