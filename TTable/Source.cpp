#include"TArrayHashTable.h"
#include"TScanTable.h"
#include"TSortTable.h"
#include"THashTable.h"
#include<locale.h>
#include<random>
#include<ctime>
#include<string>
int main()
{
	int a=30,b; int size;
	setlocale(LC_CTYPE, "Russian");
	mt19937 gen(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<> distrib(1, 1000);

	enum Table{Scantab = 1, SortTab, ArrayHash, ListHash, RBTree,AvlTree };
	while(a!=0)
	{
	cout << "�������� ��� �������:\n 1-���������������\n 2-�������������\n 3-��� �������(������)\n 4-��� �������(������)\n 5-������\n 6-��� ������\n";
	cin>>a;
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
			cout << "1-����� ��������\n2-���������� ��������\n3-�������� ��������\n";
			cin >> b;
			switch (b)
			{
			case 1:
			{
				int el;
				cout << "������� �������\n";
				cin >> el;
				if (t.Find(el))
					cout << "����� ������� ����";
				else
					cout << "������ �������� ���";
			}break;
			default:
				break;
			}
			break;

		}
		case(SortTab):
		{
			cout << "������� ���������� �������\n";
			cin >> size;
			TSortTable t(size);
			TRecord rec;
			while (!t.Full())
			{
				int rand = distrib(gen);
				rec.key = rand;
				rec.val = to_string(rand) + "**";
				t.InsRec(rec);
			}
			cout << t;
			break;
		}
		case (ArrayHash):
		{
			TArrayHashTable t(5, 1);
			break;
		}

		}

	}
}