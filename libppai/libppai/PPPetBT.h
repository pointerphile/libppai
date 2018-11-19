#pragma once
#include "PPBT.h"
#include "PPFood.h"

namespace PP {
	struct BTInfo {
		PP::PPObject* m_pPet;
		PP::PPHandle m_hTargetFood;
		PP::PPFood* m_pTargetFood;
	};

	class CheckTarget : public PP::Node {
	public:
		PP::BTInfo* m_BTInfo;
	public:
		CheckTarget(PP::BTInfo* BTInfo) : m_BTInfo(BTInfo) {};
		virtual bool Run() override;
	};

	class ActionSearchFood : public PP::Node {
	public:
		PP::BTInfo* m_BTInfo;
	public:
		ActionSearchFood(PP::BTInfo* BTInfo) : m_BTInfo(BTInfo) {};
		virtual bool Run() override;
	};

	class ActionChaseFood : public PP::Node {
	public:
		PP::BTInfo* m_BTInfo;
	public:
		ActionChaseFood(PP::BTInfo* BTInfo) : m_BTInfo(BTInfo) {};
		virtual bool Run() override;
	};

	class ActionEatFood : public PP::Node {
	public:
		PP::BTInfo* m_BTInfo;
	public:
		ActionEatFood(PP::BTInfo* BTInfo) : m_BTInfo(BTInfo) {};
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
		PP::BTInfo m_BTInfo;
		PP::Sequence* m_pRoot;
	public:
		PPPetBT(PP::PPObject *pObject);
		~PPPetBT();
	};
}

