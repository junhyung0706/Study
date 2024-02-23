#pragma once
#include <iostream>

class RAM
{
public:
	RAM(int sz);
	virtual~RAM();
private:
	int* memory;
	int size;
public:
	void write(int index, int value);
	int read(int index);
};