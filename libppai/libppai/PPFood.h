#pragma once
#include "PPObject.h"
namespace PP {
	class PPFood : public PP::PPObject {
	public:
		int iQuantity;
	public:
		PPFood();
		virtual ~PPFood();
	};
}