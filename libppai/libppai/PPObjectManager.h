#pragma once
#include "PPSingleton.h"
#include "PPPet.h"
#include "PPFood.h"

namespace PP {
	class PPObjectManager : public PP::PPSingleton<PPObjectManager>
	{
	public:
		std::map<PP::PPHandle, PP::PPObject*> m_mapObject;
		uint64_t m_iID = 0;
	public:
		PPObjectManager();
		~PPObjectManager();
	public:
		PPHandle push_back_Pet_m(int iPosition);
		PPHandle push_back_Food_m(int iPosition, int iQuantity);
		bool CheckElement_m(PP::PPHandle Handle);
		void erase_m(PP::PPHandle Handle);
		void* GetpObject(PP::PPHandle Handle);
	};
}
