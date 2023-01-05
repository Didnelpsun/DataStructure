// 动态顺序表
#include "../constant.h"

// 定义动态顺序表
typedef struct {
    // 动态分配数组指针
    ElemType *data;
    // 数组最大容量
    unsigned int maxSize;
    // 数组当前元素个数
    unsigned int length;
} DynamicSequenceList;