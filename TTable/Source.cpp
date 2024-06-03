#include"TArrayHashTable.h"
#include"TScanTable.h"
#include"TSortTable.h"
#include"THashTable.h"
#include "TListHash.h"
#include "TAVLTree.h"
#include<locale.h>
#include<random>
#include<ctime>
#include<string>

template <class T>
void actions(T& t)
{
	int b = -1;
	while (b != 0)
	{
		cout << "1-����� ��������\n2-���������� ��������\n3-�������� ��������\n0-�����\n";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			t.SetZeroEff();
			int el;
			cout << "������� �������\n";
			cin >> el;
			if (t.Find(el))
				cout << "����� ������� ����\n";
			else
				cout << "������ �������� ���\n";
			cout << "�������������: " << t.getEff() << endl << endl;
			break;
		}

		case 2:
		{
			t.SetZeroEff();
			int el;
			cout << "������� �������\n";
			cin >> el;
			TRecord rec;
			rec.key = el;
			rec.val = to_string(el) + "**";
			t.Insert(rec);
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			break;
		}
		case 3:
		{
			t.SetZeroEff();
			int el;
			cout << "������� �������\n";
			cin >> el;
			t.Delete(el);
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			break;
		}
		}
	}
}

int main()
{
	int a = -1;
	int size, step;
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));
	enum Table { Scantab = 1, SortTab, ArrayHash, ListHash, Tree, AvlTree};
	while (a != 0)
	{
		cout << "�������� ��� �������:\n 1-���������������\n 2-�������������\n 3-��� �������(������)\n 4-��� �������(������)\n 5-������\n 6-��� ������\n 0-�����\n";
		cin >> a;
		switch (a)
		{
		case (Scantab):
		{
			cout << "������� ���������� �������\n";
			cin >> size;
			TScanTable t(size);
			TRecord rec;
			while (!t.Full())
			{
				int r = rand() % 1001;
				rec.key = r;
				rec.val = to_string(r) + "**";
				t.Insert(rec);
			}
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			actions(t);

			break;
		}
		case(SortTab):
		{
			cout << "������� ���������� �������\n";
			cin >> size;
			TScanTable t(size);
			TRecord rec;
			while (!t.Full())
			{
				int r = rand() % 1001;
				rec.key = r;
				rec.val = to_string(r) + "**";
				t.Insert(rec);
			}
			cout << t;
			TSortTable sort(size);
			sort.ScanToSort(t);
			actions(sort);
			break;
		}
		case (ArrayHash):
		{
			cout << "������� ���������� �������\n";
			cin >> size;
			cout << "������� ��� �����������\n";
			cin >> step;
			TArrayHashTable t(size, step);
			TRecord rec;
			while (!t.Full())
			{
				int r = rand() % 1001;
				rec.key = r;
				rec.val = to_string(r) + "**";
				t.Insert(rec);
			}
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		case (ListHash):
		{
			cout << "������� ���������� �������\n";
			cin >> size;
			TListHash t(size);
			TRecord rec;
			while (!t.Full()) {
				int r = rand() % 1001;
				rec.key = r;
				rec.val = to_string(r) + "**";
				t.Insert(rec);
			}
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		case (Tree):
		{
			cout << "������� ���������� �������\n";
			cin >> size;
			TTreeTable t;
			TRecord rec;
			for (int i = 0; i < size; ++i) {
				int r = rand() % 1001;
				rec.key = r;
				rec.val = to_string(r) + "**";
				t.Insert(rec);
			}
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		case (AvlTree):
		{
			cout << "������� ���������� �������\n";
			cin >> size;
			AVLTree t;
			TRecord rec;
			for (int i = 0; i < size; ++i) {
				int r = rand() % 1001;
				rec.key = r;
				rec.val = to_string(r) + "**";
				t.Insert(rec);
			}
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		}
	}
}