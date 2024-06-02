#include"TArrayHashTable.h"
#include"TScanTable.h"
#include"TSortTable.h"
#include"THashTable.h"
#include<locale.h>
#include<random>
#include<ctime>
#include<string>
template <class T>
void actions(T t)
{
	int b=30;
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
			t.InsRec(rec);
			cout << "�������������: " << t.getEff() << endl << endl;
			break;
		}
		case 3:
		{
			t.SetZeroEff();
			int el;
			cout << "������� �������\n";
			cin >> el;
			t.DelRec(el);
			cout << "�������������: " << t.getEff() << endl << endl;
			break;
		}

		}
	}
}

int main()
{
	int a = 30, b = 30; int size, step;
	setlocale(LC_CTYPE, "Russian");
	mt19937 gen(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<> distrib(1, 1000);
	enum Table { Scantab = 1, SortTab, ArrayHash, ListHash, RBTree, AvlTree };
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
				int rand = distrib(gen);
				rec.key = rand;
				rec.val = to_string(rand) + "**";
				t.InsRec(rec);
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
				int rand = distrib(gen);
				rec.key = rand;
				rec.val = to_string(rand) + "**";
				t.InsRec(rec);
			}
			cout << t;
			TSortTable sort(size);
			sort.ScanToSort(t);
			actions(t);
		
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
				int rand = distrib(gen);
				rec.key = rand;
				rec.val = to_string(rand) + "**";
				t.InsRec(rec);
			}
			cout << t;
			cout << "�������������: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		}
	}
}