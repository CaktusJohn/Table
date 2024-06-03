#include "../TTable/TAVLTree.h" 
#include "gtest.h"
#include "string"

TEST(AVLTree, Can_Create_AVLTree)
{
	ASSERT_NO_THROW(AVLTree tree);
}

TEST(AVLTree, New_AVLTree_Is_Empty)
{
	AVLTree tree;
	EXPECT_EQ(true, tree.Empty());
}

TEST(AVLTree, Can_getDataCount)
{
	AVLTree tree;
	std::string val;

	for (int i = 0; i < 5; i++)
	{
		val = std::to_string(i);
		TRecord record(i, val);
		tree.Insert(record);
	}

	EXPECT_EQ(5, tree.getDataCount());
}

TEST(AVLTree, Can_Reset)
{
	AVLTree tree1;
	std::string val;
	for (int i = 1; i < 10; i++)
	{
		val = std::to_string(i);
		if (i <= 4)
		{
			TRecord record(i + 3, val);
			tree1.Insert(record);
		}
		else {
			TRecord record(i - 4, val);
			tree1.Insert(record);
		}
	}
	tree1.Reset();
	EXPECT_EQ(1, tree1.getRecord().key);
}

TEST(AVLTree, Can_IsEnd)
{
	AVLTree tree;
	TRecord rec4(4, "4");
	tree.Insert(rec4);
	TRecord rec3(3, "3");
	tree.Insert(rec3);
	tree.Reset();
	tree.GoNext();
	tree.GoNext();
	EXPECT_EQ(true, tree.IsEnd());
}

TEST(AVLTree, Can_GoNext)
{
	AVLTree tree;
	ASSERT_ANY_THROW(tree.GoNext());

	TRecord rec4(4, "4");
	tree.Insert(rec4);
	TRecord rec2(2, "2");
	tree.Insert(rec2);
	TRecord rec3(3, "3");
	tree.Insert(rec3);
	TRecord rec6(6, "6");
	tree.Insert(rec6);
	TRecord rec5(5, "5");
	tree.Insert(rec5);
	tree.Reset();
	for (int i = 2; i <= 6; i++)
	{
		EXPECT_EQ(i, tree.getRecord().key);
		tree.GoNext();
	}

	ASSERT_ANY_THROW(tree.GoNext());
}

TEST(AVLTree, Can_Find)
{
	AVLTree tree;
	TRecord rec(1, "1");
	tree.Insert(rec);
	EXPECT_FALSE(tree.Find(2));
	TRecord rec2(2, "2");
	tree.Insert(rec2);
	EXPECT_TRUE(tree.Find(2));
}

TEST(AVLTree, Can_Insert)
{
	AVLTree tree;
	TRecord rec4(4, "4");
	tree.Insert(rec4);
	TRecord rec3(3, "3");
	tree.Insert(rec3);
	TRecord rec2(2, "2");
	tree.Insert(rec2);
	TRecord rec5(5, "5");
	tree.Insert(rec5);
	TRecord rec6(6, "6");
	tree.Insert(rec6);

	EXPECT_EQ(-1, tree.GetRighTkey(6));
	TRecord rec7(7, "7");
	tree.Insert(rec7);
	EXPECT_EQ(7, tree.GetRighTkey(6));

	EXPECT_EQ(-1, tree.GetLefTkey(2));
	TRecord rec1(1, "1");
	tree.Insert(rec1);
	EXPECT_EQ(1, tree.GetLefTkey(2));
}

TEST(AVLTree, Can_Delete_Root)
{
	AVLTree tree;
	TRecord rec52(52, "52");
	tree.Insert(rec52);
	TRecord rec43(43, "43");
	tree.Insert(rec43);
	TRecord rec21(21, "21");
	tree.Insert(rec21);
	TRecord rec45(45, "45");
	tree.Insert(rec45);
	TRecord rec60(60, "60");
	tree.Insert(rec60);
	TRecord rec57(57, "57");
	tree.Insert(rec57);
	TRecord rec70(70, "70");
	tree.Insert(rec70);


	EXPECT_EQ(60, tree.GetRighTkey(52));
	EXPECT_EQ(43, tree.GetLefTkey(52));
	EXPECT_EQ(-1, tree.GetRighTkey(57));
	EXPECT_EQ(-1, tree.GetLefTkey(57));
	EXPECT_EQ(70, tree.GetRighTkey(60));
	EXPECT_EQ(57, tree.GetLefTkey(60));
	tree.Delete(52);
	EXPECT_EQ(60, tree.GetRighTkey(57));
	EXPECT_EQ(43, tree.GetLefTkey(57));
	EXPECT_EQ(70, tree.GetRighTkey(60));
	EXPECT_EQ(-1, tree.GetLefTkey(60));
}

TEST(AVLTree, Can_Delete_From_The_End)
{
	AVLTree tree;
	TRecord rec1(104, "52");
	tree.Insert(rec1);
	TRecord rec2(43, "43");
	tree.Insert(rec2);
	TRecord rec3(21, "21");
	tree.Insert(rec3);
	TRecord rec4(60, "60");
	tree.Insert(rec4);
	TRecord rec5(57, "57");
	tree.Insert(rec5);

	EXPECT_EQ(104, tree.GetRighTkey(60));
	tree.Delete(104);
	EXPECT_EQ(-1, tree.GetRighTkey(60));
}