#include <iostream>
#include "UHeap.h"
void main()
{
	priority_elem<int> A(1, 3);
	priority_elem<int> B(2, 3);
	std::cout << (A>B);
	std::cout << (A<B);
}