#pragma once
#include "TTable.h"
#include <stack>
#define  H_OK 0
#define  H_INC 1
#define  H_DEC -1
#define  BalRight 1
#define  BalOK 0
#define  BalLeft -1

struct TTreeNode {
	TRecord rec;
	TTreeNode* pLeft, * pRight;
	int bal;
	TTreeNode(const TRecord& _rec)
	{
		rec = _rec;
		pLeft = nullptr;
		pRight = nullptr;
		bal = BalOK;
	}
};


class TTreeTable :public TTable
{
protected:

	TTreeNode* pRoot, * pCurr, * pPrev;
	std::stack<TTreeNode*> st;
	int countpos{}, lvl{};


public:

	TTreeTable()
	{
		pRoot = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
		countpos = 0; lvl = 0;
		DataCount = 0;
	}

	TTreeTable& operator =(const TTreeTable& other)
	{
		DeleteTreeTab(pRoot);
		pRoot = other.pRoot;
		pCurr = other.pCurr;
		pPrev = other.pPrev;
		countpos = 0; lvl = 0;
		DataCount = 0;
		return *this;
	}
	TTreeNode* getRoot()
	{
		return pRoot;
	}

	bool Find(Tkey key)
	{
		if (pCurr != nullptr)
		{
			if (pCurr->rec.key == key)
			{
				return true;
			}
		}
		pCurr = pRoot; pPrev = nullptr;
		while (pCurr != nullptr)
		{
			eff++;
			if (pCurr->rec.key == key) break;
			else {
				pPrev = pCurr;
				if (pCurr->rec.key > key)
				{
					pCurr = pCurr->pLeft;
				}
				else {
					pCurr = pCurr->pRight;
				}
			}
		}
		if (pCurr != nullptr) {
			return true;
		}
		else {
			pCurr = pPrev;
			return false;
		}

	}
	bool Insert(TRecord _rec)
	{
		if (Find(_rec.key))
		{
			cout << "Такой элемент уже есть\n";
			return false;
		}
		else
		{
			TTreeNode* newNode = new TTreeNode(_rec);
			if (pRoot == nullptr)
			{
				pRoot = newNode;

			}
			else
			{
				if (pCurr->rec.key > _rec.key)
				{
					pCurr->pLeft = newNode;

				}
				else
				{
					pCurr->pRight = newNode;
				}
			}
			DataCount++;
			eff++;
			return true;
		}
	}
	bool Delete(Tkey key)
	{
		if (!Find(key)) return false;
		TTreeNode* pDel = pCurr;
		if (pCurr->pRight == nullptr)
		{
			if (pPrev == nullptr)  pRoot = pRoot->pLeft;
			else
			{
				if (pCurr->rec.key > pPrev->rec.key)
				{
					pPrev->pRight = pCurr->pLeft;
				}
				else
				{
					pPrev->pLeft = pCurr->pLeft;
				}
			}

		}
		else if (pCurr->pLeft == nullptr)
		{
			if (pPrev == nullptr)  pRoot = pRoot->pRight;
			else
			{
				if (pCurr->rec.key > pPrev->rec.key)
				{
					pPrev->pRight = pCurr->pRight;
				}
				else
				{
					pPrev->pLeft = pCurr->pRight;
				}
			}

		}
		else
		{
			TTreeNode* tmp = pCurr->pLeft;
			pPrev = pCurr;
			while (tmp->pRight != nullptr)
			{
				eff++;
				pPrev = tmp;
				tmp = tmp->pRight;
			}
			pCurr->rec = tmp->rec;
			if (pPrev != pCurr)
			{
				pPrev->pRight = tmp->pLeft;
			}
			else
			{
				pPrev->pLeft = tmp->pLeft;
			}
			pDel = tmp;
		}
		eff++;
		delete pDel;
		DataCount--;
		return true;
	}

	void Reset()
	{
		while (!st.empty())
		{
			st.pop();
		}
		pCurr = pRoot;
		while (pCurr != nullptr)
		{
			st.push(pCurr);
			pCurr = pCurr->pLeft;
		}
		pCurr = st.top();
		countpos = 0;
	}
	void GoNext()
	{
		if (pCurr == nullptr || IsEnd())
		{
			throw std::exception();
		}
		if (!st.empty())
		{
			st.pop();
		}
		if (pCurr->pRight != nullptr)
		{
			pCurr = pCurr->pRight;
			while (pCurr != nullptr)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
			pCurr = st.top();
		}
		else if (!st.empty())
		{
			pCurr = st.top();
		}
		countpos++;
	}
	bool IsEnd()
	{
		return countpos == DataCount;
	}

	void DeleteTreeTab(TTreeNode* pNode)
	{
		if (pNode != nullptr)
		{
			DeleteTreeTab(pNode->pLeft);
			DeleteTreeTab(pNode->pRight);
			delete pNode;
		}
	}
	~TTreeTable()
	{
		DeleteTreeTab(pRoot);
		pRoot = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
		countpos = 0; lvl = 0;
		DataCount = 0;
	}

	bool Full() { return false; };
	TRecord getRecord() { return pCurr->rec; };
	void SetCurrentRecord(TRecord record)
	{
		pCurr->rec.key = record.key;
		pCurr->rec.val = record.val;
	};


	Tkey GetRighTkey(Tkey key)
	{
		Find(key);
		if (pCurr->pRight == nullptr)
		{
			return -1;
		}
		else
		{
			return pCurr->pRight->rec.key;
		}
	}
	Tkey GetLefTkey(Tkey key)
	{
		Find(key);
		if (pCurr->pLeft == nullptr)
		{
			return -1;
		}
		else
		{
			return pCurr->pLeft->rec.key;
		}
	}
	Tkey GetRooTkey()
	{
		return pRoot->rec.key;
	}

	ostream& PrintTable(ostream& os, TTreeNode* pNode){
		if (pNode != nullptr)
		{
			for (int i = 0; i < lvl; i++)
			{
				os << " ";
			}
			os << pNode->rec.key << std::endl;
			lvl++;
			PrintTable(os, pNode->pRight);
			PrintTable(os, pNode->pLeft);
			lvl--;
		}
		return os;
	}

	friend ostream& operator <<(ostream& os, TTreeTable& t) {
		TTreeNode* pNode = t.getRoot();
		t.PrintTable(os, pNode);
		return os;
	}
};

