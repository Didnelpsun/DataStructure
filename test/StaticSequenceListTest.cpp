// 静态顺序表测试
#include "../header/tool.h"
#include "../header/StaticSequenceList/operation.h"
#include "../header/StaticSequenceList/implement.h"

// 测试插入
void Insert() {
    StaticSequenceList list;
    InitStaticSequenceList(&list);
    ElemType elems[5] = {2, 3, 4, 5, 2};
    InsertStaticSequenceLists(&list, 0, elems, 5);
    PrintStaticSequenceList(list);
//    InsertStaticSequenceLists(&list, 3, elems, 1);
    InsertStaticSequenceList(&list, 3, elems[1]);
    PrintStaticSequenceList(list);
}

// 测试删除
void Delete() {
    StaticSequenceList list;
    InitStaticSequenceList(&list);
    ElemType elems[5] = {2, 3, 4, 5, 2};
    InsertStaticSequenceLists(&list, 0, elems, 5);
    PrintStaticSequenceList(list);
    DeleteStaticSequenceLists(&list, 0, 3);
    PrintStaticSequenceList(list);
    DeleteStaticSequenceList(&list, 0);
    PrintStaticSequenceList(list);
}

// 测试实现
void Implement() {
    StaticSequenceList list;
    InitStaticSequenceList(&list);
    ElemType elems[5] = {2, 3, 4, 5, 2};
    InsertStaticSequenceLists(&list, 0, elems, 5);
    PrintStaticSequenceList(list);
//    Print(GetMaxStaticSequenceList(list));
//    ReverseStaticSequenceList(&list);
//    DeleteElemStaticSequenceList(&list,3);
    RotateStaticSequenceList(&list,-2);
    PrintStaticSequenceList(list);
}

// 总测试
void StaticSequenceListTest() {
//    Insert();
//    Delete();
    Implement();
}
