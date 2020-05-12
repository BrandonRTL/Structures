#include "UHeap.h"
#include <gtest.h>
TEST(THeap, can_create_default_heap)
{

	EXPECT_NO_THROW(heap<int>());
}
TEST(THeap, can_find_child)
{
	heap<int> H;

	EXPECT_EQ(H.approachMyChild(1, 1), 3);
}
TEST(THeap, can_find_parent)
{
	heap<int> H;
	priority_elem<int> A(1, 3);
	H.data.push_back(A);
	H.data.push_back(A);

	EXPECT_EQ(H.parent(1),0);
}
TEST(THeap, cant_find_my_daddy)
{
	heap<int> H;

	EXPECT_ANY_THROW(H.parent(0));
}
TEST(THeap, cant_find_unexisting_min_child)
{
	heap<int> H;
	priority_elem<int> A1(1, 3); //Lame ON
	priority_elem<int> A2(2, 3); 
	priority_elem<int> A3(3, 3);
	H.data.push_back(A1);
	H.data.push_back(A2);
	H.data.push_back(A3);// Lame OFF

	EXPECT_EQ(H.minChild(2),-1);
}
TEST(THeap, can_find_min_child_2)
{
	heap<int> H;
	priority_elem<int> A1(1, 3); //Lame ON
	priority_elem<int> A2(2, 3);
	priority_elem<int> A3(3, 3);
	priority_elem<int> A4(4, 3);
	priority_elem<int> A5(5, 3);
	H.data.push_back(A1);
	H.data.push_back(A3);
	H.data.push_back(A2);
	H.data.push_back(A4);
	H.data.push_back(A5); // Lame OFF


	EXPECT_EQ(H.minChild(0), 2);
}
TEST(THeap, can_make_heap)
{
	heap<int> H;
	priority_elem<int> A1(1, 3); //Lame ON
	priority_elem<int> A2(2, 3);
	priority_elem<int> A3(3, 3);
	priority_elem<int> A4(4, 3);
	priority_elem<int> A5(5, 3);
	priority_elem<int> A6(6, 3);
	priority_elem<int> A7(7, 3);
	H.data.push_back(A7);
	H.data.push_back(A6);
	H.data.push_back(A5);
	H.data.push_back(A4);
	H.data.push_back(A3);
	H.data.push_back(A2);
	H.data.push_back(A1);
	std::vector<int> Pr0;
	std::vector<int> Pr = {1,3,2,4,6,7,5};// Lame OFF
	H.makeHeap();
	for (int i = 0; i < H.data.size(); i++)
	{
		Pr0.push_back(H.data[i].priority);
	}

	EXPECT_EQ(Pr0, Pr);
}
