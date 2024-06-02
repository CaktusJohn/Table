#include "../TTable/TSortTable.h"
#include "../TTable/TSortTable.cpp"
#include "gtest.h"
#include "string"
#include<random>
#include<ctime>

TEST(TSortTable, can_create_TSortTable)
{
    ASSERT_NO_THROW(TSortTable table(10));
}

TEST(TSortTable, new_TSortTable_is_empty)
{
    TSortTable table(10);
    EXPECT_TRUE(table.Empty());
}

TEST(TSortTable, TSortTable_is_sorted)
{
    TSortTable table(10);
    string str = "a";
    for (int i = 0; i > 10; i++)
    {
        TRecord tmp;
        tmp.key = i;
        tmp.val = to_string(i) + str;
        table.InsRec(tmp);
    }
    int j = 1;
    for (table.Reset(); !table.IsEnd(); table.GoNext())
    {
        EXPECT_TRUE(table.getRecord().key == j);
        j++;
    }
}

TEST(TSortTable, can_insert_in_empty_TSortTable)
{
    TSortTable table(10);
    string str = "a";
    TRecord a;
    a.key=1;
    a.val = str;
    ASSERT_NO_THROW(table.InsRec(a));
    table.Find(1);
    EXPECT_TRUE(a == table.getRecord());
}


TEST(TSortTable, cant_insert_new_Record_in_Full_TSortTable)
{
    mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> distrib(1, 1000);
    TSortTable t(10);
    TRecord rec;
    while (!t.Full())
    {
        int rand = distrib(gen);
        rec.key = rand;
        rec.val = to_string(rand) + "**";
        t.InsRec(rec);
    }
    ASSERT_ANY_THROW(t.InsRec(rec));

}



