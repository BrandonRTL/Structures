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
TEST(TList, can_push_element)
{
	List<int> A;
	EXPECT_NO_THROW(A.push_back(3));
}