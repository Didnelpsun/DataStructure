// 顺序表
#include "../Header/constant.h"
#include "Linear.h"

class SequenceList : public Linear {
private:
    // 私有成员
    ElemType *_data{};
public:
    // Getter
    ElemType *GetData() override;

    ElemType GetData(unsigned int index) override;

    // Setter
    bool SetData(ElemType *data) override;

    bool SetData(unsigned int index, ElemType data) override ;
};

ElemType *SequenceList::GetData() {
    return this->_data;
}

ElemType SequenceList::GetData(unsigned int index) {
    if (index < this->GetLength())
        return this->_data[index];
    return NULL;
}

bool SequenceList::SetData(ElemType *data) {
    if (data != nullptr){
        this->_data = data;
        return true;
    }
    return false;
}

bool SequenceList::SetData(unsigned int index, ElemType data) {
    if (index < this->GetLength()) {
        this->_data[index] = data;
        return true;
    }
    return false;
}
