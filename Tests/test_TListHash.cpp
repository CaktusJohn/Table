#include "../TTable/TListHash.h"
#include "gtest.h"
#include "string"

TEST(TListHash, Can_Create_TListHash)
{
    ASSERT_NO_THROW(TListHash table(10));
}

TEST(TListHash, Cant_Create_TListHash_With_Size_more_Then_MaxSize)
{
    ASSERT_ANY_THROW(TListHash table(9999999));
}

TEST(TListHash, Can_Get_Size_TListHash)
{
    TListHash table(10);
    int size = table.GetSize();
    EXPECT_TRUE(size == 10);
}

TEST(TListHash, New_TListHash_Is_Empty)
{
    TListHash table(10);
    EXPECT_EQ(true, table.Empty());
}

TEST(TListHash, Can_Insert_New_Record_In_Empty_TListHash)
{
    TListHash table(10);
    std::string str = "1";
    TRecord a(1, str);
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.getRecord());
}

TEST(TListHash, Can_Insert_New_Record_In_Last_Position_In_TListHash)
{
    TListHash table(10);
    for (int i = 0; i < 9; i++)
    {
        TRecord tmp(i, std::to_string(i));
        table.Insert(tmp);
    }

    int count = table.getDataCount();
    EXPECT_TRUE(count == 9);
    TRecord a(10, "10");
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(10);
    EXPECT_TRUE(a == table.getRecord());
}

TEST(TListHash, Can_Delete_First_Record_From_TListHash)
{
    TListHash table(10);

    TRecord a(1, "1");
    table.Insert(a);
    table.Find(1);
    EXPECT_TRUE(a == table.getRecord());

    ASSERT_NO_THROW(table.Delete(1));
    EXPECT_TRUE(table.getDataCount() == 0);
}

TEST(TListHash, Cant_Delete_Record_From_Empty_TListHash)
{
    TListHash table(10);
    ASSERT_ANY_THROW(table.Delete(1));
}

TEST(TListHash, Can_Delete_Record_From_Mid_In_TListHash_table)
{
    TListHash table(10);
    TRecord a(1, "1");
    for (int i = 0; i < 10; i++)
    {
        TRecord tmp(i, std::to_string(i));
        table.Insert(tmp);
    }

    int count = table.getDataCount();
    EXPECT_TRUE(count == 10);

    table.Delete(4);
    bool val = table.Find(4);
    EXPECT_TRUE(val == false);
    EXPECT_TRUE(table.getDataCount() == 9);
}