#include "TArrayHashTable.h"
ostream& operator<<(ostream& os, TArrayHashTable t)
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
