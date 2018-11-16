#include "PPPetBT.h"
#include "PPPet.h"
#include "PPObjectManager.h"

int main(int argc, char* argv[]) {
	std::locale::global(std::locale(""));

	PP::PPObjectManager::GetInstance().m_listObject.emplace_back();

	std::system("pause");
	return 0;
}