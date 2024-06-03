#include "../TTable/TScanTable.h"
#include "../TTable/TScanTable.cpp"
#include "gtest.h"
#include "string"
#include<random>
#include<ctime>

TEST(TScanTable, can_create_Table)
{
    ASSERT_NO_THROW(TScanTable table(10));
}


TEST(TScanTable, new_Table_is_empty)
{
    TScanTable table(10);
    EXPECT_TRUE(table.Empty());
}

TEST(TScanTable, can_insert)
{
    TScanTable table(10);
    string str = "aaa";
    TRecord a;
    a.key = 1;
    a.val = str;
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.getRecord());
}

TEST(TScanTable, cant_insert_new_Record_in_Full_TScanTable)
{
    mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> distrib(1, 1000);
    TScanTable t(10);
    TRecord rec;
    while (!t.Full())
    {
        int rand = distrib(gen);
        rec.key = rand;
        rec.val = to_string(rand) + "**";
        t.Insert(rec);
    }
    ASSERT_ANY_THROW(t.Insert(rec));
    
}






