// 有序顺序表
#include "SequenceList.h"
#include "SortedList.h"

class SortedSequenceList : public SequenceList, public SortedList {
public:
    // 排序顺序表无法移位
    void Rotate(int step) override;
};

void SortedSequenceList::Rotate(int step) {
    std::cout << "[SortedSequenceList::Rotate]:can't rotate" << std::endl;
}
