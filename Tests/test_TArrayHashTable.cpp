#include "../TTable/TArrayHashTable.h"
#include "gtest.h"
#include "string"
#include<random>
#include<ctime>
TEST(TArrayHashTable, can_create_Table)
{
    ASSERT_NO_THROW(TArrayHashTable table(10,4));
}
TEST(TArrayHashTable, eff_is_correct)
{
    TArrayHashTable t(10, 2);
    TRecord rec1;
    rec1.key = 8;
    rec1.val = "dsf";
    TRecord rec2;
    rec2.val = "dwg";
    rec2.key = 18;
    int eff1, eff2;
    t.InsRec(rec1);
    eff1 = t.getEff();
    t.SetZeroEff();
    t.InsRec(rec2);
    eff2 = t.getEff();
    EXPECT_TRUE(eff1 < eff2);
}

TEST(TArrayHashTable, can_insert)
{
    TArrayHashTable table(10,5);
    string str = "aaa";
    TRecord a;
    a.key = 1;
    a.val = str;
    ASSERT_NO_THROW(table.Insert(a));
    table.Find(1);
    EXPECT_TRUE(a == table.getRecord());
}

TEST(TArrayHashTable, cant_insert_new_Record_in_Full_ArrayHashTable)
{
    mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> distrib(1, 1000);
    TArrayHashTable t(10,5);
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
TEST(TArrayHashTable, can_delete)
{
    TArrayHashTable tab(10, 3);
    TRecord rec;
    rec.key = 2;
    rec.val = "fs";
    tab.Insert(rec);
    tab.Delete(2);
    EXPECT_EQ(tab.getRecord().key, -2);
}