#include "PPTestBT.h"

PP::PPTestBT::PPTestBT() {
	m_pRoot->AddChild(m_pSelector);
	m_pSelector->AddChild(m_pActionCheck);
	m_pSelector->AddChild(m_pSequence);
	m_pSequence->AddChild(m_pActionApproach);
	m_pSequence->AddChild(m_pActionOpen);
}
PP::PPTestBT::~PPTestBT() {}

bool PP::PPTestBT::Run() {
	while (!m_pRoot->Run()) {
		std::cout << std::endl;
	}
	std::wcout << L"에리쨩을 덮쳤다." << std::endl;
	return false;
}

bool PP::ActionCheckIfDoorIsOpen::Run() {
	if (m_pStatus->isDoorOpen == true) {
		std::wcout << L"문이 열려있는게 보인다." << std::endl;
	}
	else {
		std::wcout << L"문이 닫혀있는게 보인다." << std::endl;
	}
	return m_pStatus->isDoorOpen;
}

bool PP::ActionApproachDoor::Run() {
	if (m_isObstructed) {
		std::wcout << L"문으로 가는 길이 막혔다." << std::endl;
		return false;
	}
	if (m_pStatus->iDistanceToDoor > 0) {
		std::wcout << L"문으로 가고있다." << std::endl;
		m_pStatus->iDistanceToDoor--;
		std::wcout << L"문은 "<< m_pStatus->iDistanceToDoor << L" m 앞에 있다." << std::endl;
	}
	else {
		std::wcout << L"문 앞에 있다." << std::endl;
	}
	return true;
}

bool PP::ActionOpenDoor::Run() {
	if (m_pStatus->iDistanceToDoor > 0) {
		std::wcout << L"지금 문 앞이 아니다." << std::endl;
		return false;
	}
	else {
		m_pStatus->isDoorOpen = true;
		std::wcout << L"문을 열었다." << std::endl;
		return true;
	}
}
