#include "UStack.h"
#include <gtest.h>

TEST(TStack, can_create_stack)
{
	EXPECT_NO_THROW(TStack<int>(3));
}
TEST(TStack, cant_create_stack_with_negative_size)
{
	EXPECT_ANY_THROW(TStack<int>(-3));
}
TEST(TStack, can_push_element)
{
	TStack<int> A;
	A.Push(3);

	EXPECT_EQ(3, A.Top());
}
TEST(TStack, can_pop_element)
{
	TStack<int> A;
	A.Push(3);
	A.Push(2);
	A.Pop();

	EXPECT_EQ(3, A.Top());
}
TEST(TStack, returns_Is_Empty_1)
{
	TStack<int> A;

	EXPECT_EQ(1, A.IsEmpty());
}
TEST(TStack, returns_Is_Empty_2)
{
	TStack<int> A;
	A.Push(13);
	A.Pop();

	EXPECT_EQ(1, A.IsEmpty());
}
TEST(TStack, cant_pop_from_empty_stack)
{
	TStack<int> A;

	EXPECT_ANY_THROW(A.Pop());
}
TEST(TStack, cant_top_from_empty_stack)
{
	TStack<int> A;

	EXPECT_ANY_THROW(A.Top());
}
TEST(TStack, can_assing_stacks)
{
	TStack<int> A,B;
	A.Push(13);
	B = A;

	EXPECT_EQ(B.Top(), 13);
}
TEST(TStack, can_assing_empty_stack)
{
	TStack<int> A, B;
	B = A;

	EXPECT_ANY_THROW(B.Top());
}
TEST(TStack, can_clear_stack)
{
	TStack<int> A;
	A.Push(1);
	A.Push(1);
	A.Push(1);
	A.Clear();

	EXPECT_EQ(1, A.IsEmpty());
}







