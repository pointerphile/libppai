#pragma once
#include "ppinclude.h"

namespace PP {
	template<class T> class PPSingleton {
	public:
		static T& GetInstance()
		{
			static T SingleInstance;
			return SingleInstance;
		}
	};
}