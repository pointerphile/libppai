#pragma once
#include "PPObject.h"
#include "PPPetBT.h"

namespace PP {
	class PPPet : public PP::PPObject {
	public:
		PPPetBT m_BT = PPPetBT(this);
	public:
		PPPet();
		virtual ~PPPet();
	public:
		void SetPPPet(int iPosition);
	};
}
