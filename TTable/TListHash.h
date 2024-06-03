#pragma once
#include "THashTable.h"
#include <list>
class TListHash : public THashTable
{
protected:
	std::list<TRecord>* pList;
	int size, CurrList;
	std::list<TRecord>::iterator pCurr;
public:
	virtual int HashFunc(Tkey key) override
	{
		return key + 10;
	}

	TListHash(int _size = MAX_SIZE)
	{
		if (_size > MAX_SIZE)
		{
			throw std::exception();
		}
		size = _size;
		CurrList = 0;
		pList = new std::list<TRecord>[size];
		DataCount = 0;
	}

	~TListHash()
	{
		if (getDataCount()) {
			pList->clear();
			DataCount = 0;
		}
	}

	TListHash& operator =(const TListHash& other)
	{
		delete[] pList;
		size = other.size;
		pList = new std::list<TRecord>[size];
		DataCount = other.DataCount;
		return *this;
	}

	bool Find(Tkey _key)
	{
		CurrList = HashFunc(_key) % size;
		for (pCurr = pList[CurrList].begin(); pCurr != pList[CurrList].end(); pCurr++)
		{
			eff++;
			if (pCurr->key == _key)
			{
				return true;
			}
		}
		return false;
	}

	bool Insert(TRecord record)
	{
		bool isfind = Find(record.key);
		if (isfind) { return false; }
		else
		{
			pList[CurrList].push_front(record);
			DataCount++;
			eff++;
		}
		return true;
	}

	bool Delete(Tkey _key)
	{
		if (this->Empty())
		{
			throw std::exception();
		}

		bool isfind = Find(_key);
		if (!isfind) { return false; }
		else
		{
			pList[CurrList].erase(pCurr);
			DataCount--;
		}
		return true;
	}

	void Reset()
	{
		CurrList = 0;
		pCurr = pList[CurrList].begin();
		while (pCurr == pList[CurrList].end())
		{
			CurrList++;
			if (CurrList < size)
			{
				pCurr = pList[CurrList].begin();
			}
			else
			{
				break;
			}
		}
	}

	void GoNext()
	{
		pCurr++;
		while (pCurr == pList[CurrList].end())
		{
			CurrList++;
			if (CurrList < size)
			{
				pCurr = pList[CurrList].begin();
			}
			else
			{
				int i = 0;
				break;
			}
		}
	}

	bool Full()
	{
		if (DataCount == size)
			return true;
		else
		{
			return false;
		}
	};

	bool IsEnd()
	{
		return CurrList == size;
	}

	int GetSize() { return size; }

	virtual int GetCurrentPos() { return CurrList; }

	virtual void SetCurrentPos(int _curPos)
	{
		if (_curPos < size)
		{
			CurrList = _curPos;
		}
		else {
			throw std::exception();
		}
	}

	void SetCurrentRecord(TRecord record)
	{
		if (CurrList<0 && CurrList>size)
		{
			throw std::exception();
		}
		pList[CurrList].push_front(record);

	}

	TRecord getRecord()
	{
		return *pCurr;
	}

	friend ostream& operator<<(ostream& os, TListHash t)
	{
		cout << setw(10) << "Ключ" << setw(12) << "Значение\n";
		t.Reset();
		while (!t.IsEnd())
		{
			os << t.getRecord() << endl;
			t.GoNext();
		}
		return os;
	}

};

