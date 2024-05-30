#include "TScanTable.h"
void TScanTable::DelRec(Tkey key)
{
	eff = 0;
	if (Find(key))
	{
		pRecs[CurrPos] = pRecs[DataCount - 1];
		DataCount--;
		eff++;
	}

}
void TScanTable::InsRec(TRecord rec)
{
	eff = 0;
	if (Full()) throw("table is full");
	if (Find(rec.key))
		cout << "Такой элемент уже есть\n";
	else {
		pRecs[CurrPos] = rec;
		DataCount++;
		eff++;
	}
}
bool TScanTable::Find(Tkey key)
{
	eff = 0;
	for (int i = 0; i < DataCount; i++)
	{

		eff++;
		if (pRecs[i].key == key)
		{
			CurrPos = i;
			return true;
		}
	}
	CurrPos = DataCount;
	return false;
}
ostream& operator<<(ostream& os, TScanTable t)
{
	cout << setw(10) << "Ключ" << setw(12) << "Значение\n";
	t.Reset();
	while(!t.IsEnd())
	{
		os << t.getRecord() << endl;
		t.GoNext();
	}
	return os;
}