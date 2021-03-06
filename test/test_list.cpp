#include "UList.h"
#include <gtest.h>
#include <vector>
/*
TEST(TList, can_create_default_list)
{

	EXPECT_NO_THROW(List<int>());
}
TEST(TList, can_create_list_with_positive_size)
{

	EXPECT_NO_THROW(List<int>(3));
}
TEST(TList, cant_create_list_with_neganive_size)
{

	EXPECT_ANY_THROW(List<int>(-3));
}
TEST(TList, can_push_back_element)
{
	List<int> A;

	EXPECT_NO_THROW(A.push_back(3));
}
TEST(TList, can_remove_element)
{
	List<int> A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.Remove(0);

	EXPECT_EQ(4, A[1]);
}
TEST(TList, can_insert_element)
{
	List<int> A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.Insert(5, 2);

	EXPECT_EQ(5, A[2]);
}
TEST(TList, can_push_front_element)
{
	List<int> A;

	EXPECT_NO_THROW(A.push_front(3));
	EXPECT_EQ(3, A[0]);
}
TEST(TList, can_pop_front_element)
{
	List<int> A;
	A.push_back(3);
	A.push_back(3);
	A.pop_front();

	EXPECT_EQ(1, A.GetSize());
}
TEST(TList, can_pop_back_element)
{
	List<int> A;
	A.push_back(2);
	A.push_back(3);

	EXPECT_EQ(3, A.pop_back());
	EXPECT_EQ(1, A.GetSize());
}
TEST(TList, can_get_size)
{
	List<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);

	EXPECT_EQ(3, A.GetSize());
}
TEST(TList, can_get_size_of_empty_list)
{
	List<int> A;

	EXPECT_EQ(0, A.GetSize());
}
TEST(TList, can_get_element)
{
	List<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);

	EXPECT_EQ(3, A[2]);
}
TEST(TList, cant_get_element_with_negative_index)
{
	List<int> A;

	EXPECT_ANY_THROW(A[-1]);
}
TEST(TList, cant_get_element_with_too_big_index)
{
	List<int> A;

	EXPECT_ANY_THROW(A[1]);
}
TEST(TList, can_get_front_element)
{
	List<int> A;
	A.push_back(2);
	A.push_back(1);

	EXPECT_EQ(2, A.Front());
}
TEST(TList, can_get_back_element)
{
	List<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);

	EXPECT_EQ(4, A.Back());
}
TEST(TList, cant_get_front_element_from_empty_list)
{
	List<int> A;

	EXPECT_ANY_THROW(A.Front());
}
TEST(TList, can_pop_front)
{
	List<int> A;
	A.push_back(1);
	A.push_back(2);
	EXPECT_EQ(1, A.Front());
	EXPECT_EQ(1, A[0]);
	A.pop_front();

	EXPECT_EQ(2, A.Front());
	EXPECT_EQ(2, A[0]);
}
/*
TEST(TList, Memory)
{
	List<int> A;
	for (int i = 0; i < 100000; i++)
	{
		std::cout << i << " ";
		ASSERT_NO_THROW(A.push_back(0));
	}
	for (int i = 0; i < 100000; i++)
	{
		std::cout << i << " ";
		ASSERT_NO_THROW(List<int> list(1000));
	}
}
*//*
TEST(TMy_List_For_Iterator, can_creatr_MIFL)
{
	List<int> A;

	EXPECT_NO_THROW(auto iter = A.begin());
}
TEST(TMy_List_For_Iterator, equal_iterators_are_equal)
{
	List<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	auto iter1 = A.begin();
	auto iter2 = A.begin();

	EXPECT_EQ(1, iter1 == iter2);
}
TEST(TMy_List_For_Iterator, notequal_iterators_are_not_equal)
{
	List<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	auto iter1 = A.begin();
	auto iter2 = A.begin();
	iter2++;

	EXPECT_EQ(1, iter1 != iter2);
}
TEST(TMy_List_For_Iterator,can_go_throught_the_list)
{
	List<int> A;
	std::vector<int> B, C1;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	C1.push_back(1);
	C1.push_back(2);
	C1.push_back(3);
	for (auto iter = A.begin(); iter != A.end(); iter++)
	{
		std::cout << *iter << std::endl;
		B.push_back(*iter);
	}

	EXPECT_EQ(B, C1);
}
*/