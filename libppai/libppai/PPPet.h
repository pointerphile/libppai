#pragma once
#include "PPObject.h"
namespace PP {
	class PPPet : public PP::PPObject
	{
	public:
		int iHunger;
	public:
		PPPet();
		virtual ~PPPet();
	};
}
