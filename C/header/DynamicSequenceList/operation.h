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
    printf("maxSize:%d\nlength:%d\n", list.maxSize, list.length);
}

// 增长数组多个元素
void IncreaseDynamicSequenceLists(DynamicSequenceList *list, int size) {
    ElemType *space = (ElemType *) realloc(list->data, list->maxSize + size);
    if (space == NULL) {
        printf("分配空间失败");
        return;
    }
    list->data = space;
    // 增长成功才能增加容量
    list->maxSize += size;
}

// 增长数组单个元素
void IncreaseDynamicSequenceList(DynamicSequenceList *list) {
    IncreaseDynamicSequenceLists(list, 1);
}

// 插入多个元素
int
InsertDynamicSequenceLists(DynamicSequenceList *list, unsigned int position, const ElemType *elems, unsigned int size) {
    // 检测范围
    if (position > list->length) {
        printf("插入位置非法");
        return 1;
    }
    // 检查存储空间
    if (list->length + size > list->maxSize)
        IncreaseDynamicSequenceLists(list, size);
    // 将i位置的元素后移size位
    for (unsigned int i = list->length + size; i >= position + size; i--)
        list->data[i] = list->data[i - size];
    for (unsigned int i = 0; i < size; i++)
        list->data[position + i] = elems[i];
    list->length += size;
    return 0;
}

// 插入单个元素
int InsertDynamicSequenceList(DynamicSequenceList *list, unsigned int position, ElemType elem) {
    return InsertDynamicSequenceLists(list, position, &elem, 1);
}

// 删除多个元素
ElemType *DeleteDynamicSequenceLists(DynamicSequenceList *list, unsigned int position, unsigned int length) {
    ElemType *result = (ElemType *) malloc(sizeof(ElemType) * length);
    // 检测范围
    if (position + length > list->length) {
        printf("删除位置非法");
        return NULL;
    }
    // 将被删除元素复制给result
    // 将元素前移
    for (unsigned int i = position; i < list->length; i++) {
        result[i - position] = list->data[i];
        list->data[i] = list->data[i + length];
    }
    list->length -= length;
    return result;
}

// 删除一个元素
ElemType DeleteDynamicSequenceList(DynamicSequenceList *list, unsigned int position) {
    return DeleteDynamicSequenceLists(list, position, 1)[0];
}

// 查找一个元素
int SearchDynamicSequenceList(DynamicSequenceList list, ElemType elem) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == elem)
            return i;
    }
    return -1;
}