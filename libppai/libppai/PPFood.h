#pragma once
#include "PPObject.h"
namespace PP {
	class PPFood : public PP::PPObject {
	public:
		int m_iQuantity;
	public:
		PPFood();
		virtual ~PPFood();
	public:
		void SetPPFood(int iPosition, int iQuantity);
	};
}