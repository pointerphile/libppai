#include "PPPetBT.h"
#include "PPPet.h"
#include "PPObjectManager.h"

int main(int argc, char* argv[]) {
	std::locale::global(std::locale(""));
	PP::PPPet* pPet = (PP::PPPet*)PP::PPObjectManager::GetInstance().push_back_Pet(1);
	PP::PPObjectManager::GetInstance().erase(pPet);

	std::system("pause");
	return 0;
}