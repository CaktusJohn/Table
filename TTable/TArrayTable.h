#pragma once
#include"TTable.h"
class TArrayTable: public TTable
{	 
protected:
	TRecord * pRecs; // память для записей таблицы
	int TabSize;// макс. возм. к-во записей
	int CurrPos;// номер текущего записи (нумерация от 0)
public:
	TArrayTable(int Size)
	{
		TabSize = Size;
		pRecs = new TRecord[TabSize];
		CurrPos = -1;
	}
	~TArrayTable()
	{
		delete[] pRecs;
	}
	TArrayTable(const TArrayTable& tab)
	{
		TabSize = tab.TabSize;
		pRecs = new TRecord[TabSize];
		for (int i = 0; i < tab.DataCount; i++)
		{
			pRecs[i] = tab.pRecs[i];
		}
		CurrPos = tab.CurrPos;
		DataCount = tab.DataCount;
	}
	TArrayTable& operator= (const TArrayTable& tab)
	{
		
			delete pRecs;
			TabSize = tab.TabSize;
			pRecs = new TRecord[TabSize];
			for (int i = 0; i < tab.DataCount; i++)
			{
				pRecs[i] = tab.pRecs[i];
			}
			CurrPos = tab.CurrPos;
			return *this;
	}
virtual bool Full() 
{
	return (DataCount >= TabSize);
} 
int GetTabSize()
{
	return TabSize;
}
virtual TRecord getRecord()
{
	if (CurrPos >= 0 && CurrPos < TabSize)
		return pRecs[CurrPos];
	else throw ("current element is wrong");
}


virtual void Reset() // установить на первую запись
{
	CurrPos = 0;
}
virtual bool IsEnd()
{
	return (CurrPos == DataCount);
}
virtual void GoNext()
{
	CurrPos++;
}
};

