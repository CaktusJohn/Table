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
		cout << "1-поиск элемента\n2-добавление элемента\n3-удаление элемента\n0-выход\n";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			t.SetZeroEff();
			int el;
			cout << "¬ведите элемент\n";
			cin >> el;
			if (t.Find(el))
				cout << "“акой элемент есть\n";
			else
				cout << "“акого элемента нет\n";
			cout << "Ёффективность: " << t.getEff() << endl << endl;
			break;
		}

		case 2:
		{
			t.SetZeroEff();
			int el;
			cout << "¬ведите элемент\n";
			cin >> el;
			TRecord rec;
			rec.key = el;
			rec.val = to_string(el) + "**";
			t.Insert(rec);
			cout << t;
			cout << "Ёффективность: " << t.getEff() << endl << endl;
			break;
		}
		case 3:
		{
			t.SetZeroEff();
			int el;
			cout << "¬ведите элемент\n";
			cin >> el;
			t.Delete(el);
			cout << t;
			cout << "Ёффективность: " << t.getEff() << endl << endl;
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
		cout << "¬ыберите тип таблицы:\n 1-неупор€доченна€\n 2-упор€доченна€\n 3-хеш таблица(массив)\n 4-хеш таблица(список)\n 5-дерево\n 6-ј¬Ћ дерево\n 0-выход\n";
		cin >> a;
		switch (a)
		{
		case (Scantab):
		{
			cout << "¬ведите количество записей\n";
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
			cout << "Ёффективность: " << t.getEff() << endl << endl;
			actions(t);

			break;
		}
		case(SortTab):
		{
			cout << "¬ведите количество записей\n";
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
			cout << "¬ведите количество записей\n";
			cin >> size;
			cout << "¬ведите шаг хешировани€\n";
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
			cout << "Ёффективность: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		case (ListHash):
		{
			cout << "¬ведите количество записей\n";
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
			cout << "Ёффективность: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		case (Tree):
		{
			cout << "¬ведите количество записей\n";
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
			cout << "Ёффективность: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		case (AvlTree):
		{
			cout << "¬ведите количество записей\n";
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
			cout << "Ёффективность: " << t.getEff() << endl << endl;
			actions(t);
			break;
		}
		}
	}
}