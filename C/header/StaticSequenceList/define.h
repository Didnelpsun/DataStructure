// 静态顺序表
#include "../constant.h"

// 定义静态顺序表
typedef struct {
    // 顺序表元素
    ElemType data[MAX_SIZE];
    // 顺序表长度
    unsigned int length;
} StaticSequenceList;