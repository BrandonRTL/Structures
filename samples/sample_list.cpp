#include <iostream>
#include "UList.h"
void main()
{
	List<int> a;
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);
	a.Insert(7, 0);
	a.Remove(1);
	for (int i = 0; i < a.GetSize(); i++)
		std::cout << a[i] << std::endl;
}