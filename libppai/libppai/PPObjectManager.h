#pragma once
#include "PPSingleton.h"
#include "PPPet.h"
#include "PPFood.h"

namespace PP {
	class PPObjectManager : public PP::PPSingleton<PPObjectManager>
	{
	public:
		std::list<PP::PPObject*> m_listpObject;
		std::map<PP::PPHandle, PP::PPObject*> m_mapObject;
		uint64_t m_iID = 0;
	public:
		PPObjectManager();
		~PPObjectManager();
	public:
		//void* push_back_Pet(int iPosition);
		PPHandle push_back_Pet_m(int iPosition);
		//void* push_back_Food(int iPosition, int iQuantity);
		PPHandle push_back_Food_m(int iPosition, int iQuantity);
		//bool CheckElement(PP::PPObject* pObject);
		bool CheckElement_m(PP::PPHandle Handle);
		//void erase(PP::PPObject* pObject);
		void erase_m(PP::PPHandle Handle);
		void* GetpObject(PP::PPHandle Handle);
	};
}
