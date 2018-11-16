#pragma once
#include "PPBT.h"

namespace PP {
	class CheckFood : PP::Node {
		virtual bool Run() override;
	};

	class ActionEatFood : PP::Node {
	public:
		virtual bool Run() override;
	};

	class ActionChaseFood : PP::Node {
	public:
		virtual bool Run() override;
	};

	class PPPetBT {
	private:
		int &iPosition;
		PP::Sequence* m_pRoot;
		PP::Sequence* m_pSequence;
		PP::Selector* m_pSelector;
		PP::CheckFood* m_pCheckFood;
		PP::ActionEatFood* m_ActionEatFood;
		PP::ActionChaseFood* m_ActionChaseFood;
	public:
		PPPetBT();
		~PPPetBT();
	};
}

