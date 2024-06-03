#include "TScanTable.h"
bool TScanTable::Delete(Tkey key)
{
	if (Find(key))
	{
		pRecs[CurrPos] = pRecs[DataCount - 1];
		DataCount--;
		eff++;
		return true;
	}
	else return false;
}
bool TScanTable::Insert(TRecord rec)
{
	if (Full()) {
		throw("table is full");
		return false;
	}
	if (Find(rec.key)) {
		cout << "Такой элемент уже есть\n";
		return false;
	}
	else {
		pRecs[CurrPos] = rec;
		DataCount++;
		eff++;
		return true;
	}
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