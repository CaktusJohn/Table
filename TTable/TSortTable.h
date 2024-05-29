#pragma once
#include "TScanTable.h"
class TSortTable : public TScanTable//есть сомнеия в правильности констр копирования +добавить 2 функции сортировок и функц sort + доделать delrec
{
protected:
	TRecord* pBuff;
public:
	TSortTable(int _size):TScanTable(_size)
	{
		pBuff = new TRecord[_size];
	}
	TSortTable(const TScanTable& st)
	{
		*this= st;
		Sort();
	}

	void Sort()
	{
		enum Sort{Quiq=1,Merge,Select};
		int a;
		cout << "Выберите тип сортировки: 1-быстрая 2-слиянием 3-вставкой\n";
		cin >> a;	
		switch (a)
		{
		case (Quiq):
			Qsort(0,DataCount-1);
			break;
		case (Merge):
			MergeTableSort();
			break;
		case (Select):
			TableSelectSort();
			break;
		default:
			cout << "error\n";
		}
	}
	void QuickTableSort()
	{
		Qsort(0, DataCount - 1);
	}
	void MergeTableSort()
	{
		merge_sort(0, DataCount - 1);
	}
	void TableSelectSort()
	{
		sort_select(DataCount);
	}
	//TSortTable& operator= (const TSortTable& t); не понятно зачем нужен
	void Qsort(int l,int r);
	void merge(int left, int mid, int right);//слиянием
	void merge_sort(int left, int right);
	void sort_select(int size);
	bool Find(Tkey key);
	void InsRec(TRecord rec)
	{
		if (Full())
		{
			cout << "table is full";
		}
		else
		{
			bool res = Find(rec.key);
			if (!res)
			{
				for (int i = DataCount - 1; i >= CurrPos; i--)
				{

					eff++;
					pRecs[i + 1] = pRecs[i];

				}
				pRecs[CurrPos] = rec;
				DataCount++;
			}
		}
	}
	/*void DelRec(Tkey key)
	{
		bool res = Find(key);
		if (res)
		{
			for (int i = CurrPos; i < DataCount; i++)
			{
				eff++;
				pRecs[i] = pRecs[i+1];
			}
			pRecs[CurrPos] = rec;
			DataCount++;
		}
	}*/
	friend ostream& operator<<(ostream& os, TSortTable t);
};
