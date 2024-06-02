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
		cout << "1-поиск элемента\n2-добавление элемента\n3-удаление элемента\n0-выход\n";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			t.SetZeroEff();
			int el;
			cout << "Введите элемент\n";
			cin >> el;
			if (t.Find(el))
				cout << "Такой элемент есть\n";
			else
				cout << "Такого элемента нет\n";
			cout << "Эффективность: " << t.getEff() << endl << endl;
			break;
		}

		case 2:
		{
			t.SetZeroEff();
			int el;
			cout << "Введите элемент\n";
			cin >> el;
			TRecord rec;
			rec.key = el;
			rec.val = to_string(el) + "**";
			t.InsRec(rec);
			cout << "Эффективность: " << t.getEff() << endl << endl;
			break;
		}
		case 3:
		{
			t.SetZeroEff();
			int el;
			cout << "Введите элемент\n";
			cin >> el;
			t.DelRec(el);
			cout << "Эффективность: " << t.getEff() << endl << endl;
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
		cout << "Выберите тип таблицы:\n 1-неупорядоченная\n 2-упорядоченная\n 3-хеш таблица(массив)\n 4-хеш таблица(список)\n 5-дерево\n 6-АВЛ дерево\n 0-выход\n";
		cin >> a;
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
			}
			cout << t;
			cout << "Эффективность: " << t.getEff() << endl << endl;
			actions(t);

			break;
		}
		case(SortTab):
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
			}
			cout << t;
			TSortTable sort(size);
			sort.ScanToSort(t);
			actions(t);
		
		break;		
		}
		case (ArrayHash):
		{
			cout << "Введите количество записей\n";
			cin >> size;
			cout << "Введите шаг хеширования\n";
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
			cout << "Эффективность: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		}
	}
}