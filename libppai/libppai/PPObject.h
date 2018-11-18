#pragma once
#include "ppinclude.h"

namespace PP {
	enum PPObjectType { Object, Pet, Food };

	class PPObject {
	public:
		int m_iPosition;
		PPObjectType m_ObjectType;
	public:
		PPObject();
		virtual ~PPObject();
	};
}