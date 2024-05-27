#pragma once
#include "THashTable.h"
class TArrayHashTable:public THashTable //таблица с вторичным хешированием
{
protected:
	TRecord* pRecs;
	int MaxSize, Step, Curr, Free;
	TRecord Empty, Del;
public:
	virtual int HashFunc(Tkey key) override
	{
		return key + 10;
	}
	TArrayHashTable(int _MaxSize,int _Step)	
	{
		Step = _Step;
		MaxSize = _MaxSize;
		pRecs = new TRecord[MaxSize];
		Empty.key = -1;
		Empty.val = '0';
		Del.key = -2;
		Del.val = '0';
		for (int i = 0; i < MaxSize; i++)
		{
			pRecs[i] = Empty;
		}
	}
	~TArrayHashTable()
	{
		delete pRecs;
	}
	void Reset()
	{
		for (Curr = 0; Curr < MaxSize; Curr++)
		{
			if (pRecs[Curr] != Empty && pRecs[Curr] != Del)
				break;
		}
	}
	bool IsEnd()
	{
		if (Curr == MaxSize) return true;
	}
	void GoNext()
	{
		for (; Curr < MaxSize; Curr++)
		{
			if (pRecs[Curr] != Empty && pRecs[Curr] != Del)
				break;
		}
	}
	bool Find(Tkey key)
	{
		Free = -1;
		Curr = HashFunc(key) % MaxSize;
		for (int t = 0; t < MaxSize; t++)
		{
			eff++;
			if (pRecs[Curr].key == key)
				return true;
			if (pRecs[Curr] == Del && Free == -1)
			{
				Free == Curr;
			}
			if (pRecs[Curr] == Empty)
			{
				return false;
			}
			Curr = (Curr + Step) % MaxSize;
		}
		return false;
	}
	void DelRec(Tkey key)
	{
		bool b=Find(key);
		if (b)
		{
			pRecs[Curr] = Del;
			DataCount--;
		}
	

	}
	void InsRec( TRecord rec)
	{
		if (Full())
		{
			return;
		}
		bool isFind = Find(rec.key);
		if (isFind)
		{
			return;
		}
		else
		{
			if (Free != -1)
				pRecs[Curr] = rec;
			DataCount++;
		}
	}
	virtual TRecord getRecord() override
	{
		if (Curr > 0 && Curr < MaxSize)
			return pRecs[Curr];
		else throw ("current element is wrong");
	}
	virtual bool Full() override
	{
		return (DataCount >= MaxSize);
	}
	
};

