#pragma once
#include "PPSingleton.h"
#include "PPPet.h"
#include "PPFood.h"

namespace PP {
	class PPObjectManager : public PP::PPSingleton<PPObjectManager>
	{
	public:
		std::list<PP::PPObject*> m_listpObject;
	public:
		PPObjectManager();
		~PPObjectManager();
	public:
		void* push_back_Pet(int iPosition);
		void* push_back_Food(int iPosition, int iQuantity);
		bool CheckElement(PP::PPObject* pObject);
		void erase(PP::PPObject* pObject);
	};
}
