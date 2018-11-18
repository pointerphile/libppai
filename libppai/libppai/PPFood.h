#pragma once
#include "PPObject.h"
namespace PP {
	class PPFood : public PP::PPObject {
	public:
		int m_iQuantity;
	public:
		PPFood(int iPosition, int iQuantity);
		virtual ~PPFood();
	};
}