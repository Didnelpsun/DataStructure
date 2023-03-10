#include "operation.h"

// 获取最小值，返回对应索引值
int GetMinDynamicSequenceList(DynamicSequenceList list) {
    int min = 0;
    for (int i = 0; i < list.length; i++) {
        if (list.data[min] > list.data[i])
            min = i;
    }
    return min;
}

// 获取最大值，返回对应索引值
int GetMaxDynamicSequenceList(DynamicSequenceList list) {
    int max = 0;
    for (int i = 0; i < list.length; i++) {
        if (list.data[max] < list.data[i])
            max = i;
    }
    return max;
}

// 逆置顺序表
void ReverseDynamicSequenceList(DynamicSequenceList *list) {
    ElemType temp;
    for (int i = 0; i < list->length / 2; i++) {
        temp = list->data[i];
        list->data[i] = list->data[list->length - 1 - i];
        list->data[list->length - 1 - i] = temp;
    }
}

// 删除所有指定值元素，返回出现次数
int DeleteElemDynamicSequenceList(DynamicSequenceList *list, ElemType elem) {
    // 删除指定值后索引偏移值，即出现次数
    int dev = 0;
    for (int i = 0; i < list->length; i++) {
        // 如果不等就证明该位置的值要保留
        if (list->data[i] != elem) {
            // 如果前面不存在指定值就证明没有要删除的
            // 如果不等于0证明要删除部分元素，从而前移
            if (dev != 0)
                list->data[i - dev] = list->data[i];
        }
            // 如果相等即不需要移动，偏移值自增
        else {
            dev++;
        }
    }
    // 把偏移量减去即得最后删除后的长度
    list->length -= dev;
    return dev;
}

// 循环移动，右移为正方向
void RotateDynamicSequenceList(DynamicSequenceList *list, int step) {
    // 新建一个数组
    ElemType *data = (ElemType *) malloc(sizeof(ElemType) * list->length);
    // 移动
    for (int i = 0; i < list->length; i++) {
        data[(i + step +  list->length) % list->length] = list->data[i];
    }
    list->data = data;
}

