#include "PPTestBT.h"

PP::PPTestBT::PPTestBT() {}
PP::PPTestBT::~PPTestBT() {}

bool PP::ActionCheckIfDoorIsOpen::Run() {
	if (pStatus->isDoorOpen == true) {
		std::wcout << L"문이 열려있다." << std::endl;
	}
	else {
		std::wcout << L"문이 닫혀있다." << std::endl;
	}
	return pStatus->isDoorOpen;
}
