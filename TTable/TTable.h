#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

typedef int Tkey;
typedef string Tval;

constexpr size_t MAX_SIZE = 999;

struct TRecord
{
	Tkey key;
	Tval val;

	TRecord()
	{
		key = 0;
		val = "";
	}

	TRecord(Tkey key, Tval value)
	{
		this->key = key;
		this->val = value;
	}

	friend ostream& operator<<(ostream& os,TRecord record)
	{
		os<<setw(10) << record.key<< setw(10)<< record.val << endl;
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
	void SetZeroEff()
	{
		eff = 0;
	}
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
	
	virtual bool Full() = 0;
	virtual bool Find(Tkey key) = 0;
	virtual bool Insert(TRecord rec) = 0;
	virtual bool Delete(Tkey key) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual TRecord getRecord() = 0;
};
 