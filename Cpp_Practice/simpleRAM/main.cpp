#include "Memory.h"

int main()
{
	RAM mem(10);
	mem.write(0,100);
	mem.write(1, 200);

	std::cout << "0번지의 데이터: " << mem.read(0) << std::endl;
	std::cout << "1번지의 데이터: " << mem.read(1) << std::endl;

	return 0;
}