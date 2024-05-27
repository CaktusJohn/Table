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
	int a; int size;
	setlocale(LC_CTYPE, "Russian");
	mt19937 gen(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<> distrib(1, 1000);

	enum Table{Scantab = 1, SortTab, ArrayHash, ListHash, RBTree,AvlTree };
	cout << "Выберите тип таблицы:\n 1-неупорядоченная\n 2-упорядоченная\n 3-хеш таблица(массив)\n 4-хеш таблица(список)\n 5-дерево\n 6-АВЛ дерево\n";
	
	cin>>a;
	while (a != 0)
	{


		switch (a)
		{
		case (Scantab):
		{
			cout << "Введите количество записей\n";
			cin >> size;
			TScanTable t(size);
			TRecord rec;
			while (!t.Full())
			{
				int rand = distrib(gen);
				rec.key = rand;
				rec.val = to_string(rand) + "**";
				t.InsRec(rec);
				cout << t.getRecord();
			}
			//cout << t;
			break;

		}
		case(SortTab):
		{
			cout << "Введите количество записей\n";
			cin >> size;
			TSortTable t(size);
			TRecord rec;
			while (!t.Full())
			{
				int rand = distrib(gen);
				rec.key = rand;
				rec.val = to_string(rand) + "**";
				t.InsRec(rec);
				cout << t.getRecord();

			}
			t.Sort();
			t.Reset();
			while (!t.IsEnd())
			{
				cout << t.getRecord() << endl;
				t.GoNext();
			}
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