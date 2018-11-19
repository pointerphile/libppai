#include "PPPetBT.h"
#include "PPPet.h"
#include "PPObjectManager.h"
#include <Windows.h>

int main(int argc, char* argv[]) {
	std::locale::global(std::locale(""));
	//PP::PPPet* pPet = (PP::PPPet*)PP::PPObjectManager::GetInstance().push_back_Pet(5);
	//PP::PPFood* pFood0 = (PP::PPFood*)PP::PPObjectManager::GetInstance().push_back_Food(8, 2);
	//PP::PPFood* pFood1 = (PP::PPFood*)PP::PPObjectManager::GetInstance().push_back_Food(6, 2);
	//PP::PPFood* pFood2 = (PP::PPFood*)PP::PPObjectManager::GetInstance().push_back_Food(1, 2);

	PP::PPHandle hPet = PP::PPObjectManager::GetInstance().push_back_Pet_m(5);
	PP::PPPet* pPet = (PP::PPPet*)PP::PPObjectManager::GetInstance().GetpObject(hPet);
	PP::PPHandle hFood0 = PP::PPObjectManager::GetInstance().push_back_Food_m(8, 2);
	PP::PPHandle hFood1 = PP::PPObjectManager::GetInstance().push_back_Food_m(6, 2);
	PP::PPHandle hFood2 = PP::PPObjectManager::GetInstance().push_back_Food_m(1, 2);

	while (1) {
		pPet->m_BT.m_pRoot->Run();
		std::cout << std::endl;
		Sleep(2000);
	}


	std::system("pause");
	return 0;
}