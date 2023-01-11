// 顺序表
#include "Linear.h"

class SequenceList : public Linear {
private:
    // 私有成员
    ElemType *_data{};
    unsigned int _maxSize{};
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
    void PrintData() override;

    void PrintSequenceList();

    bool Increase();

    bool Increase(unsigned int size);

    bool Insert(ElemType elem) override;

    bool Insert(ElemType elem, unsigned int index) override;

    bool Insert(ElemType *elems, unsigned int index, unsigned int size) override;

    ElemType Delete() override;

    ElemType Delete(unsigned int index) override;

    ElemType *Delete(unsigned int index, unsigned int length) override;

    int Search(ElemType elem) override;

    unsigned int Min() override;

    unsigned int Max() override;

    void Reverse() override;

    unsigned int DeleteElem(ElemType elem) override;

    virtual void Rotate(int step);
};

SequenceList::SequenceList() {
    this->_data = new ElemType[MAX_SIZE];
    this->_maxSize = MAX_SIZE;
    this->SetLength(0);
}

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
    return this->_maxSize;
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
    this->_maxSize = maxSize;
    return true;
}

void SequenceList::PrintData() {
    std::cout << "data:[";
    for (int i = 0; i < this->GetLength(); i++) {
        std::cout << this->GetData(i);
        if (i < this->GetLength() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
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

bool SequenceList::Insert(ElemType elem) {
    return this->Insert(elem, this->GetLength());
}

bool SequenceList::Insert(ElemType elem, unsigned int index) {
    auto *elems = new ElemType[1];
    return this->Insert(elems, index, 1);
}

bool SequenceList::Insert(ElemType *elems, unsigned int index, unsigned int size) {
    if (index > this->GetLength()) {
        std::cout << "[SequenceList::Insert]:index " << index << " > max size " << this->GetLength() << std::endl;
        return false;
    }
    if (this->GetLength() + size > this->GetMaxSize())
        if (!this->Increase(size))
            return false;
    // 这一步是关键，因为SetData会根据length值限定是否能修改data，所以调用SetData前必须更新length值
    this->SetLength(this->GetLength() + size);
    // 后移
    if (index != this->GetLength()) {
        for (unsigned int i = this->GetLength() - 1; i >= index + size; i--)
            this->SetData(this->GetData(i - size), i);
    }
    // 赋值
    for (unsigned int i = 0; i < size; i++)
        this->SetData(elems[i], index + i);
    return true;
}

ElemType SequenceList::Delete() {
    ElemType *elems = this->Delete(this->GetLength() - 1, 1);
    return elems == nullptr ? (ElemType) NULL : elems[0];
}

ElemType SequenceList::Delete(unsigned int index) {
    ElemType *elems = this->Delete(index, 1);
    return elems == nullptr ? (ElemType) NULL : elems[0];
}

ElemType *SequenceList::Delete(unsigned int index, unsigned int length) {
    auto *result = new ElemType[length];
    if (index + length > this->GetLength()) {
        std::cout << "[SequenceList::Delete]:data " << index + length << " > length" << this->GetLength() << std::endl;
        return nullptr;
    }
    // 赋值
    for (unsigned int i = 0; i < length; i++)
        result[i] = this->GetData(i + index);
    // 移动
    for (unsigned int i = index; i < this->GetLength() - length; i++)
        this->SetData(this->GetData(i + length), i);
    this->SetLength(this->GetLength() - length);
    return result;
}

int SequenceList::Search(ElemType elem) {
    for (int i = 0; i < this->GetLength(); i++) {
        if (this->GetData(i) == elem)
            return i;
    }
    std::cout << "[SequenceList::Search]:can't find elem value = " << elem << std::endl;
    return -1;
}

unsigned int SequenceList::Min() {
    int min = 0;
    for (int i = 0; i < this->GetLength(); i++) {
        if (this->GetData(min) > this->GetData(i))
            min = i;
    }
    return min;
}

unsigned int SequenceList::Max() {
    int max = 0;
    for (int i = 0; i < this->GetLength(); i++) {
        if (this->GetData(max) < this->GetData(i))
            max = i;
    }
    return max;
}

void SequenceList::Reverse() {
    ElemType temp;
    for (int i = 0; i < this->GetLength() / 2; i++) {
        temp = this->GetData(i);
        this->SetData(this->GetData(this->GetLength() - i - 1), i);
        this->SetData(temp, this->GetLength() - i - 1);
    }
}

unsigned int SequenceList::DeleteElem(ElemType elem) {
    // 删除指定值后索引偏移值，即出现次数
    int dev = 0;
    for (int i = 0; i < this->GetLength(); i++) {
        // 如果不等就证明该位置的值要保留
        if (this->GetData(i) != elem) {
            // 如果前面不存在指定值就证明没有要删除的
            // 如果不等于0证明要删除部分元素，从而前移
            if (dev != 0)
                this->SetData(this->GetData(i), i-dev);
        }
            // 如果相等即不需要移动，偏移值自增
        else {
            dev++;
        }
    }
    // 把偏移量减去即得最后删除后的长度
    this->SetLength(this->GetLength() - dev);
    return dev;
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


