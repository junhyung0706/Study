#include "Memory.h"
#include <iostream>

RAM::RAM(int sz) : size(sz)
{ 
	memory = new int[size];
}

RAM::~RAM()
{
	delete[] memory;
}

void RAM::write(int index, int value)
{
        if (index >= 0 && index < size)
            memory[index] = value;
        else
            std::cout << "Invalid index" << std::endl;
}

int RAM::read(int index)
{
    if (index >= 0 && index < size) {
        return memory[index];
    }
    else {
        std::cout << "Invalid index" << std::endl;
        return -1; // 예외 처리를 위해 임의의 값 반환
    }
}