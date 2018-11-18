#include "PPPetBT.h"
#include "PPPet.h"
#include "PPObjectManager.h"
#include <Windows.h>

int main(int argc, char* argv[]) {
	std::locale::global(std::locale(""));
	PP::PPPet* pPet = (PP::PPPet*)PP::PPObjectManager::GetInstance().push_back_Pet(5);
	PP::PPFood* pFood0 = (PP::PPFood*)PP::PPObjectManager::GetInstance().push_back_Food(8, 2);
	PP::PPFood* pFood1 = (PP::PPFood*)PP::PPObjectManager::GetInstance().push_back_Food(6, 2);
	PP::PPFood* pFood2 = (PP::PPFood*)PP::PPObjectManager::GetInstance().push_back_Food(1, 2);

	while (1) {
		pPet->m_BT.m_pRoot->Run();
		std::cout << std::endl;
		Sleep(2000);
	}
	
	PP::PPObjectManager::GetInstance().erase(pPet);

	std::system("pause");
	return 0;
}