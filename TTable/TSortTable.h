#pragma once
#include "TScanTable.h"
class TSortTable : public TScanTable//есть сомнеи€ в правильности констр копировани€ +добавить 2 функции сортировок и функц sort + доделать delrec
{
protected:
	TRecord* pBuff;
public:
	TSortTable(int _size):TScanTable(_size)
	{
		pBuff = new TRecord[_size];
	}
	void ScanToSort(TScanTable& tab)
	{
		for (tab.Reset(), Reset(); !tab.IsEnd(); tab.GoNext(), GoNext())
		{
			pRecs[CurrPos] = tab.getRecord();
			DataCount++;
		}
		enum Sort{Quiq=1,Merge,Select};
		int a;
		cout << "¬ыберите тип сортировки: 1-быстра€ 2-сли€нием 3-вставкой\n";
		cin >> a;	
		switch (a)
		{
		case (Quiq):
			Qsort(0,DataCount-1);
			cout << *this;
			cout << "Ёффективность: " << getEff() << endl << endl;;
			break;
		case (Merge):
			merge_sort(0, DataCount - 1);
			cout << *this;
			cout << "Ёффективность: " << getEff() << endl << endl;;
			break;
		case (Select):
			sort_select(DataCount);
			cout << *this;
			cout << "Ёффективность: " << getEff() << endl << endl;;
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
	//TSortTable& operator= (const TSortTable& t); не пон€тно зачем нужен
	void Qsort(int l,int r);
	void merge(int left, int mid, int right);//сли€нием
	void merge_sort(int left, int right);
	void sort_select(int size);
	bool Find(Tkey key);
	bool Insert(TRecord rec)
	{
		
		if (Full())
		{
			throw("error");
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
				return true;
			}
		}
		return false;
	}
	bool Delete(Tkey key)
	{
		
		bool res = Find(key);
		if (res)
		{
			for (int i = CurrPos; i < DataCount-1; i++)
			{
				eff++;
				pRecs[i] = pRecs[i+1];
			}
			DataCount--;
			return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream& os, TSortTable t);
};
