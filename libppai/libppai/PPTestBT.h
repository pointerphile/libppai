#pragma once
#include "PPBT.h"

namespace PP {
	struct DoorStatus {
		bool isDoorOpen;
		int iDistanceToDoor;
	};

	class ActionCheckIfDoorIsOpen : public PP::Node {
	private:
		DoorStatus* m_pStatus;
	public:
		ActionCheckIfDoorIsOpen(DoorStatus* pStatus) : m_pStatus(pStatus) {}
		virtual bool Run() override;
	};

	class ActionApproachDoor : public PP::Node {
	private:
		DoorStatus* m_pStatus;
		bool m_isObstructed;
	public:
		ActionApproachDoor(DoorStatus* pStatus, bool isObstructed) : m_pStatus(pStatus), m_isObstructed(isObstructed) {}
		virtual bool Run() override;
	};

	class ActionOpenDoor : public PP::Node {
	private:
		DoorStatus* m_pStatus;
	public:
		ActionOpenDoor(DoorStatus* pStatus) : m_pStatus(pStatus) {}
		virtual bool Run() override;
	};

	class PPTestBT {
	private:
		PP::Sequence* m_pRoot = new Sequence;
		PP::Sequence* m_pSequence = new Sequence;
		PP::Selector* m_pSelector = new Selector;
		PP::DoorStatus* m_pStatus = new DoorStatus { false, 5 };
		PP::ActionCheckIfDoorIsOpen* m_pActionCheck = new ActionCheckIfDoorIsOpen(m_pStatus);
		PP::ActionApproachDoor* m_pActionApproach = new ActionApproachDoor(m_pStatus, false);
		PP::ActionOpenDoor* m_pActionOpen = new ActionOpenDoor(m_pStatus);
	public:
		PPTestBT();
		~PPTestBT();
	public:
		bool Run();
	};
}