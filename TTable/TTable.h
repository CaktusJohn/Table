#pragma once
#include<iostream>
using namespace std;

typedef int Tkey;
typedef string Tval;
struct TRecord
{
	Tkey key;
	Tval val;
	friend ostream& operator<<(ostream& os,TRecord record)
	{
		os << record.key << " " << record.val << endl;
		return os;
	}
	bool operator!= (const TRecord& rec)
	{
		if (key != rec.key || val != rec.val)
			return true;
		else return false;
	}
	bool operator== (const TRecord& rec)
	{
		if (key == rec.key && val == rec.val)
			return true;
		else return false;
	}
};

class TTable
{
protected:
	int DataCount;
	int eff;
public:
	virtual ~TTable() {};
	int getDataCount()
	{
		return DataCount;
	}
	int getEff()
	{
		return eff;
	}
	void ClearEff()
	{
		eff = 0;
	}
	bool Empty()
	{
		if (DataCount == 0)
			return true;
		else return false;
	}
	friend ostream& operator<<(ostream& os, TTable t)
	{
		for (t.Reset(); !t.IsEnd(); t.GoNext())
		{
			os << t.getRecord() << endl;
		}
		return os;
	}
	virtual bool Full() = 0;
	virtual bool Find(Tkey key) = 0;
	virtual void InsRec(TRecord rec) = 0;
	virtual void DelRec(Tkey key) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual TRecord getRecord() = 0;
	
};

