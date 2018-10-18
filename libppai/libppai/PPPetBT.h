#pragma once
#include "PPBT.h"

namespace PP {
	struct PetStatus {
		int iPosition;
		int iMoveSpeed;
	};

	class FoodStatus {
	public:
		int m_iPosition;
		int m_iQuantity;
	public:
		FoodStatus(int iPosition, int iQuantity);
		~FoodStatus();
	};

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
		PP::PetStatus m_pPetStatus;
		PP::FoodStatus m_pFoodStatus;
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

