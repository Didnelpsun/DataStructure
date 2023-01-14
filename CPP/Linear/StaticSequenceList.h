// 静态顺序表
#include "SequenceList.h"

class StaticSequenceList : public SequenceList {
public:
    bool Insert(ElemType elem) override ;

    bool Insert(ElemType *elems, unsigned int index, unsigned int size) override ;
};

bool StaticSequenceList::Insert(ElemType elem) {
    if (this->GetLength() < this->GetMaxSize())
        return Linear::Insert(elem);
    std::cout << "[StaticSequenceList::Insert]:index " << this->GetLength() + 1 << " > max size " << this->GetMaxSize() << std::endl;
    return false;
}

bool StaticSequenceList::Insert(ElemType *elems, unsigned int index, unsigned int size) {
    if (this->GetLength() + size <= this->GetMaxSize())
        return SequenceList::Insert(elems, index, size);
    std::cout << "[StaticSequenceList::Insert]:index " << this->GetLength() + size << " > max size " << this->GetMaxSize() << std::endl;
    return false;
}

