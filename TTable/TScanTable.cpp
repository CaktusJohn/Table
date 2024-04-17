#include "TScanTable.h"
void TScanTable::DelRec(Tkey key)
{
	if (Find(key))
	{
		pRecs[CurrPos] = pRecs[DataCount - 1];
		DataCount--;
		eff++;
	}

}
void TScanTable::InsRec(TRecord rec)
{
	if (Full()) throw("table is full");
	Find(rec.key);
	pRecs[CurrPos] = rec;
	DataCount++;
	eff++;
}
bool TScanTable::Find(Tkey key)
{
	for (int i = 0; i < DataCount; i++)
	{

		eff++;
		if (pRecs[i].key == key)
		{
			CurrPos = i;
			return true;
		}
		CurrPos = i;
	}

	return false;
}