#include "define.h"

// 初始化元素数组
void InitStaticSequenceList(StaticSequenceList *list) {
    list->length = 0;
}

// 打印顺序表数据
void PrintStaticSequenceListData(StaticSequenceList list) {
    printf("data:[");
    for (int i = 0; i < list.length; i++) {
        printf("%d", list.data[i]);
        if (i < list.length - 1)
            printf(",");
    }
    printf("]\n");
}

// 打印顺序表
void PrintStaticSequenceList(StaticSequenceList list) {
    PrintStaticSequenceListData(list);
    printf("length:%d\n", list.length);
}

// 插入多个
int
InsertStaticSequenceLists(StaticSequenceList *list, const ElemType *elems, unsigned int index, unsigned int size) {
    // 检测范围
    if (index > list->length) {
        printf("插入未知非法");
        return 1;
    }
    // 检查存储空间
    if (list->length + size > MAX_SIZE) {
        printf("数组越界");
        return 1;
    }
    // 将i位置的元素后移size位
    // i > index + size这里没有等号，否则赋值会覆盖掉前面的length属性
    for (int i = list->length + size; i > index + size; i--)
        list->data[i] = list->data[i - size];
    for (int i = 0; i < size; i++)
        list->data[index + i] = elems[i];
    list->length += size;
    return 0;
}

// 插入单个
int InsertStaticSequenceList(StaticSequenceList *list, ElemType elem, unsigned int index) {
    return InsertStaticSequenceLists(list, &elem, index, 1);
}

// 删除多个元素
ElemType *DeleteStaticSequenceLists(StaticSequenceList *list, unsigned int index, unsigned int length) {
    ElemType *result = (ElemType *) malloc(sizeof(ElemType) * length);
    // 检测范围
    if (index + length > list->length) {
        printf("删除位置非法");
        return NULL;
    }
    // 将被删除元素复制给result
    for (unsigned int i = 0; i < length; i++)
        result[i] = list->data[i + index];
    // 将元素前移
    for (unsigned int i = index; i < list->length - length; i++)
        list->data[i] = list->data[i + length];
    list->length -= length;
    return result;
}

// 删除一个元素
ElemType DeleteStaticSequenceList(StaticSequenceList *list, unsigned int index) {
    return DeleteStaticSequenceLists(list, index, 1)[0];
}

// 查找一个元素
int SearchStaticSequenceList(StaticSequenceList list, ElemType elem) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == elem)
            return i;
    }
    return -1;
}