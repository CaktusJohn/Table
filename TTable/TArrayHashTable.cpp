#include "TArrayHashTable.h"
ostream& operator<<(ostream& os, TArrayHashTable t)
{
    cout << setw(10) << "����" << setw(12) << "��������\n";
    t.Reset();
    while (!t.IsEnd())
    {
        os << t.getRecord() << endl;
        t.GoNext();
    }
    return os;
}
