#include <iostream>
#include "UHeap.h"
void main()
{
	priority_elem<int> A(1, 3);
	priority_elem<int> B(2, 3);
	heap<int> H;
	std::cout << " purr/\\.../\\  MEOW-MEOW-MEOW /\\.../\\purr " << std::endl;
	std::cout << H.approachMyChild(0, 0) << std::endl;
	std::cout << H.approachMyChild(0, 1) << std::endl;
	std::cout << H.approachMyChild(1, 0) << std::endl;
	std::cout << H.approachMyChild(1, 1) << std::endl;
}