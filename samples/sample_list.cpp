#include <iostream>
#include "UList.h"
void main()
{
	List<int> a;
	MIFL<int> b,c,d, b1, d1;
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);
	a.Insert(7, 0);
	a.Remove(1);
	d1 = a.end();
	b1 = a.begin();
	b = a.GetHead();
	d = b;
	c = b;
	++c;
	d++;
	for (int i = 0; i < a.GetSize(); i++)
		std::cout << a[i] << std::endl;
	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << *b << std::endl;
	std::cout << *b1 << std::endl;
	std::cout << *c << std::endl;
	std::cout << *d << std::endl;
	std::cout << *d1 << std::endl;
	std::cout << (c ==d) << std::endl;
}