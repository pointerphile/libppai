#include "PPTestBT.h"

int main(int argc, char* argv[]) {
	std::locale::global(std::locale(""));
	PP::PPTestBT testBT;
	testBT.Run();

	std::system("pause");
	return 0;
}