//
// Created by Новиков Александр Владимирович on 13.02.2023.
//

#include "Sum.h"

extern "C"
{
Sum* allocator()
{
	return new Sum();
}

void deleter(Sum *ptr)
{
	delete ptr;
}
}

int Sum::process(int a, int b)
{
	return a + b;
}