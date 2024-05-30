#include "TSortTable.h"
bool TSortTable::Find(Tkey key)
{
    eff = 0;
	int l = 0, r = DataCount - 1;
	while (l <= r)
	{
		eff++;
		int m = (l + r) / 2;
		if (key == pRecs[m].key)
		{
			CurrPos = m;
			return true;
		}
		if (key > pRecs[m].key)
			l = m + 1;
		else
			r = m - 1;
	}
	CurrPos = l;
	return false;
}
void TSortTable::Qsort(int l, int r)
{
    if (l >= r) // Базовый случай для выхода из рекурсии
        return;

	int m = (l + r) / 2;
	Tkey key = pRecs[m].key;
    
	int i = l, j = r;
    while (i < j)
    {
        while (pRecs[i].key < key)
        {
            i++; eff++;
        }
        while (pRecs[j].key > key)
        {
            j--;
            eff++;
        }
        if (i <= j)
        {
            swap(pRecs[i], pRecs[j]);
            i++; j--; eff++;
        }
    }
		if (j > l) Qsort(l, j);
		if (i < r) Qsort(i, r);
}

void TSortTable::merge( int left, int mid, int right)//слиянием
{
    
    int i = left;
    int j = mid + 1;
    int k = left;
    while ((i <= mid) && (j <= right))
    {
        if (pRecs[i].key < pRecs[j].key)
        {
            pBuff[k] = pRecs[i]; 
            k++; i++; eff++;
        }
        else
        {
            pBuff[k]= pRecs[j]; 
            k++; j++; eff++;
        }
    }
    if (i > mid)
        while (j <= right)
        {
            pBuff[k] = pRecs[j]; 
            j++; k++; eff++;
        }
    else
        while (i <= mid)
        {
            pBuff[k] = pRecs[i]; i++; k++; eff++;
        }
    for (i = left; i <= right; i++)
    {
        pRecs[i] = pBuff[i]; eff++;
    }
}
void TSortTable::merge_sort ( int left, int right)
{
    eff = 0;
    if (left == right) return;
    int mid = (left + right) / 2;
    merge_sort( left, mid);
    merge_sort( mid + 1, right);
    merge( left, mid, right); 
}
void TSortTable::sort_select( int size)
{
    int i, j, pos, mini; eff = 0;
    for (i = 0; i < size; i++)
    {
        mini = pRecs[i].key; pos = i;
        for (j = i + 1; j < size; j++)           
        { 
            eff++;
            if (pRecs[j].key < mini)
            {
                mini = pRecs[j].key;
                pos = j;
            }
        }
        swap(pRecs[i], pRecs[pos]); 
    }
}
ostream& operator<<(ostream& os, TSortTable t)
{
    cout << setw(10) << "Ключ" << setw(12) << "Значение\n";
    t.Reset();
    while (!t.IsEnd())
    {
        os << t.getRecord() << endl;
        t.GoNext();
    }
    return os;
}
