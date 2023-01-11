// 有序表
#include "Linear.h"

class SortedList : public Linear{
private:
    // 排序状态，默认为无序0，升序1，降序-1
    short _sort = 0;
public:
    // Getter
    short GetSort();
};

short SortedList::GetSort() {
    return this->_sort;
}