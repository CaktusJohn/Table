#include "../стек/TStack.h"
#include"../стек/Tcalc.h"
#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)// То что тут написано отображается в консоли
{
  ASSERT_NO_THROW(Tstack<int> s);
}

