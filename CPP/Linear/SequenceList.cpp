#include "SequenceList.h"

void SequenceList() {
    class SequenceList list;
    list.SetData(new ElemType[MAX_SIZE]);
    list.SetLength(MAX_SIZE);
    list.SetData(1, 3);
    delete list.getData();
}
