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

	class PPTestBT
	{
	public:
		PPTestBT();
		~PPTestBT();
	};
}