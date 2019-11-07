#include "UList.h"
#include <gtest.h>

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
	A.push_back(1);

	EXPECT_EQ(1, A.Front());
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
/*TEST(TList, Memory)
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
}*/