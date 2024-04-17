#pragma once
#include "TArrayTable.h"
class TScanTable : public TArrayTable
{
public:
	TScanTable (int Size=10) : TArrayTable(Size) {};
	virtual bool Find(Tkey key);
	virtual void InsRec(TRecord rec);
	virtual void DelRec(Tkey key);

};

