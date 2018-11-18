#pragma once
#include "ppinclude.h"

namespace PP {
	enum PPObjectType { Object, Pet, Food };

	class PPObject {
	protected:
		int m_iPosition;
	public:
		PPObjectType m_ObjectType;
		PPObject();
		virtual ~PPObject();
	};
}