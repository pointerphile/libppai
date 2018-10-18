#include "PPPetBT.h"
#include "PPObjectManager.h"

int main(int argc, char* argv[]) {
	std::locale::global(std::locale(""));

	PP::FoodStatus *pFood = new PP::FoodStatus(10, 5);

	std::system("pause");
	return 0;
}