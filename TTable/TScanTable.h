#pragma once
#include "TArrayTable.h"
class TScanTable : public TArrayTable
{
public:
	TScanTable (int Size=10) : TArrayTable(Size) {};
	virtual bool Find(Tkey key);
	virtual bool Insert(TRecord rec);
	virtual bool Delete(Tkey key);
	friend ostream& operator<<(ostream& os, TScanTable t);
};

