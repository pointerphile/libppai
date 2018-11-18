#pragma once
#include "PPBT.h"
#include "PPFood.h"

namespace PP {
	class CheckTarget : public PP::Node {
	public:
		PP::PPFood** m_pTargetFood;
	public:
		CheckTarget(PP::PPFood** pFood) : m_pTargetFood(pFood) {};
		virtual bool Run() override;
	};

	class ActionSearchFood : public PP::Node {
	public:
		PP::PPObject** m_pPet;
		PP::PPFood** m_pTargetFood;
	public:
		ActionSearchFood(PP::PPObject** pPet, PP::PPFood** pFood) : m_pPet(pPet), m_pTargetFood(pFood) {};
		virtual bool Run() override;
	};

	class ActionChaseFood : public PP::Node {
	public:
		PP::PPObject** m_pPet;
		PP::PPFood** m_pTargetFood;
	public:
		ActionChaseFood(PP::PPObject** pPet, PP::PPFood** pFood) : m_pPet(pPet), m_pTargetFood(pFood) {};
		virtual bool Run() override;
	};

	class ActionEatFood : public PP::Node {
	public:
		PP::PPObject** m_pPet;
		PP::PPFood** m_pTargetFood;
	public:
		ActionEatFood(PP::PPObject** pPet, PP::PPFood** pFood) : m_pPet(pPet), m_pTargetFood(pFood) {};
		virtual bool Run() override;
	};

	class PPPetBT {
	private:
		PP::PPObject* m_pPet;
		PP::Sequence* m_pSequence0;
		PP::Sequence* m_pSequence1;
		PP::Selector* m_pSelector0;
		PP::CheckTarget* m_pCheckTarget;
		PP::ActionSearchFood* m_pActionSearchFood;
		PP::ActionChaseFood* m_ActionChaseFood;
		PP::ActionEatFood* m_ActionEatFood;
	public:
		PP::Sequence* m_pRoot;
		PP::PPFood* m_pTargetFood;
	public:
		PPPetBT(PP::PPObject *pObject);
		~PPPetBT();
	};
}

