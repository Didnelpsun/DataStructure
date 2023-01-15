// 顺序表
#include "Linear.h"

class SequenceList : public Linear {
private:
    // 私有成员
    ElemType *_data = new ElemType[MAX_SIZE];
    unsigned int _max_size = MAX_SIZE;
public:
    // 构造函数
    SequenceList();

    explicit SequenceList(unsigned int maxSize);

    // Getter
    ElemType *GetData() override;

    ElemType GetData(unsigned int index) override;

    unsigned int GetMaxSize();

    // Setter
    bool SetData(ElemType *data) override;

    bool SetData(ElemType data, unsigned int index) override;

    bool SetMaxSize(unsigned int maxSize);

    // 成员函数
    void PrintSequenceList();

    bool Increase();

    bool Increase(unsigned int size);

    bool Insert(ElemType *elems, unsigned int index, unsigned int size) override;

    void Rotate(int step) override;
};

SequenceList::SequenceList() = default;

SequenceList::SequenceList(unsigned int maxSize) {
    this->_data = new ElemType[maxSize];
}

ElemType *SequenceList::GetData() {
    return this->_data;
}

ElemType SequenceList::GetData(unsigned int index) {
    if (index < this->GetLength())
        return this->_data[index];
    std::cout << "[SequenceList::GetData]:index " << index << " > length " << this->GetLength() << std::endl;
    return (ElemType) NULL;
}

unsigned int SequenceList::GetMaxSize() {
    return this->_max_size;
}

bool SequenceList::SetData(ElemType *data) {
    if (data != nullptr) {
        this->_data = data;
        return true;
    }
    std::cout << "[SequenceList::SetData]:data is null" << std::endl;
    return false;
}

bool SequenceList::SetData(ElemType data, unsigned int index) {
    if (index < this->GetLength()) {
        this->_data[index] = data;
        return true;
    }
    std::cout << "[SequenceList::SetData]:index " << index << " > length " << this->GetLength() << std::endl;
    return false;
}

bool SequenceList::SetMaxSize(unsigned int maxSize) {
    this->_max_size = maxSize;
    return true;
}

void SequenceList::PrintSequenceList() {
    this->PrintData();
    std::cout << "length:" << this->GetLength() << std::endl << "maxSize:" << this->GetMaxSize() << std::endl;
}

bool SequenceList::Increase() {
    return this->Increase(1);
}

bool SequenceList::Increase(unsigned int size) {
    auto *data = new(this->GetData()) ElemType[this->GetMaxSize() + size];
    if (this->GetData() == nullptr) {
        std::cout << "[SequenceList::Increase]:data is null" << std::endl;
        return false;
    }
    this->SetData(data);
    this->SetMaxSize(this->GetMaxSize() + size);
    return true;
}

bool SequenceList::Insert(ElemType *elems, unsigned int index, unsigned int size) {
    if (this->GetLength() + size > this->GetMaxSize())
        if (!this->Increase(size))
            return false;
    return Linear::Insert(elems, index, size);
}

void SequenceList::Rotate(int step) {
    // 新建一个数组
    auto *data = new ElemType[this->GetLength()];
    // 移动
    for (int i = 0; i < this->GetLength(); i++) {
        data[(i + step + this->GetLength()) % this->GetLength()] = this->GetData(i);
    }
    this->SetData(data);
}

