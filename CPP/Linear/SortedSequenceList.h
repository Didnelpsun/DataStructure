// 有序顺序表
#include "SequenceList.h"
#include "SortedList.h"

class SortedSequenceList : public SequenceList, public SortedList {
public:
    // 无法外部更改排序顺序表状态，所以不提供Setter
    // 排序顺序表无法移位
    void Rotate(int step) override;
};

void SortedSequenceList::Rotate(int step) {
    std::cout << "[SortedSequenceList::Rotate]:排序顺序表无法进行移位操作" << std::endl;
}
