#include "define.h"

// 初始化元素数组
void InitDynamicSequenceList(DynamicSequenceList *list) {
    list->data = (ElemType *) malloc(sizeof(ElemType) * INIT_SIZE);
    list->maxSize = INIT_SIZE;
    list->length = 0;
}

// 打印顺序表数据
void PrintDynamicSequenceListData(DynamicSequenceList list) {
    printf("data:[");
    for (int i = 0; i < list.length; i++) {
        printf("%d", list.data[i]);
        if (i < list.length - 1)
            printf(",");
    }
    printf("]\n");
}

// 打印顺序表
void PrintDynamicSequenceList(DynamicSequenceList list) {
    PrintDynamicSequenceListData(list);
    printf("length:%d\nmaxSize:%d\n", list.length, list.maxSize);
}

// 增长数组多个元素
int IncreaseDynamicSequenceLists(DynamicSequenceList *list, int size) {
    ElemType *space = (ElemType *) realloc(list->data, list->maxSize + size);
    if (space == NULL) {
        printf("分配空间失败");
        return 1;
    }
    list->data = space;
    // 增长成功才能增加容量
    list->maxSize += size;
    return 0;
}

// 增长数组单个元素
void IncreaseDynamicSequenceList(DynamicSequenceList *list) {
    IncreaseDynamicSequenceLists(list, 1);
}

// 插入多个元素
int
InsertDynamicSequenceLists(DynamicSequenceList *list, const ElemType *elems, unsigned int index, unsigned int size) {
    // 检测范围
    if (index > list->length) {
        printf("插入位置非法");
        return 1;
    }
    // 检查存储空间
    if (list->length + size > list->maxSize)
        if (IncreaseDynamicSequenceLists(list, size) == 1)
            return 1;
    // 将i位置的元素后移size位
    for (unsigned int i = list->length + size; i >= index + size; i--)
        list->data[i] = list->data[i - size];
    for (unsigned int i = 0; i < size; i++)
        list->data[index + i] = elems[i];
    list->length += size;
    return 0;
}

// 插入单个元素
int InsertDynamicSequenceList(DynamicSequenceList *list, ElemType elem, unsigned int index) {
    return InsertDynamicSequenceLists(list, &elem, index, 1);
}

// 删除多个元素
ElemType *DeleteDynamicSequenceLists(DynamicSequenceList *list, unsigned int index, unsigned int length) {
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
ElemType DeleteDynamicSequenceList(DynamicSequenceList *list, unsigned int index) {
    ElemType *elems = DeleteDynamicSequenceLists(list, index, 1);
    return elems == NULL ? NULL : elems[0];
}

// 查找一个元素
unsigned int SearchDynamicSequenceList(DynamicSequenceList list, ElemType elem) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == elem)
            return i;
    }
    return -1;
}