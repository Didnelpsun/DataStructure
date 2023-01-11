#include "StaticSequenceList.h"

void StaticSequenceListTest() {
    StaticSequenceList list;
    int *data = new int[5]{1, 2, 3, 4, 5};
    list.SetData(data);
    list.SetLength(5);
    list.PrintData();
    int *d = new int[3]{6, 7, 8};
    list.Insert(d, 5, 3);
    list.PrintData();
    ElemType *result = list.Delete(2, 2);
    list.PrintData();
    for (int i = 0; i < 2; i++)
        std::cout << result[i] << std::endl;
}



