#include "../����/TStack.h"
#include"../����/Tcalc.h"
#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)// �� ��� ��� �������� ������������ � �������
{
  ASSERT_NO_THROW(Tstack<int> s);
}

