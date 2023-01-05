// 动态顺序表测试
#include "../header/tool.h"
#include "../header/DynamicSequenceList/DynamicSequenceList.h"

// 测试插入
void Insert() {
    DynamicSequenceList list;
    InitDynamicSequenceList(&list);
    ElemType elems[5] = {2, 3, 4, 5, 2};
    InsertDynamicSequenceLists(&list, 0, elems, 5);
//    PrintDynamicSequenceList(list);
//    InsertDynamicSequenceLists(&list, 3, elems, 1);
    InsertDynamicSequenceList(&list, 3, elems[1]);
    PrintDynamicSequenceList(list);
}

// 测试删除
void Delete() {
    DynamicSequenceList list;
    InitDynamicSequenceList(&list);
    ElemType elems[5] = {2, 3, 4, 5, 2};
    InsertDynamicSequenceLists(&list, 0, elems, 5);
    PrintDynamicSequenceList(list);
    DeleteDynamicSequenceLists(&list, 0, 3);
    PrintDynamicSequenceList(list);
    DeleteDynamicSequenceList(&list, 0);
    PrintDynamicSequenceList(list);
}

// 测试查找
void Search() {
    DynamicSequenceList list;
    InitDynamicSequenceList(&list);
    ElemType elems[5] = {2, 3, 4, 5, 2};
    InsertDynamicSequenceLists(&list, 0, elems, 5);
    PrintDynamicSequenceList(list);
    SearchDynamicSequenceList(list, 3);
}

// 测试实现
void Implement() {
    DynamicSequenceList list;
    InitDynamicSequenceList(&list);
    ElemType elems[5] = {2, 3, 4, 5, 2};
    InsertDynamicSequenceLists(&list, 0, elems, 5);
    PrintDynamicSequenceList(list);
    Print(GetMaxDynamicSequenceList(list));
    ReverseDynamicSequenceList(&list);
//    DeleteElemDynamicSequenceList(&list,3);
//    RotateDynamicSequenceList(&list,-2);
    PrintDynamicSequenceList(list);
}

// 总测试
void DynamicSequenceListTest() {
//    Insert();
//    Delete();
    Implement();
}