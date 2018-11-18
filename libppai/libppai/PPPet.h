#pragma once
#include "PPObject.h"
#include "PPPetBT.h"

namespace PP {
	class PPPet : public PP::PPObject {
	public:
		PPPetBT m_BT;
	public:
		PPPet(int iPosition);
		virtual ~PPPet();
	public:
		void SetPet();
	};
}
