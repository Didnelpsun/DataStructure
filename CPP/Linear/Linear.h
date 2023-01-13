// 线性结构
#include "../Header/Constant.h"

class Linear {
private:
    // 私有成员
    unsigned int _length{};
public:
    // 构造函数
    Linear();

    // Getter
    virtual ElemType *GetData() = 0;

    virtual ElemType GetData(unsigned int index) = 0;

    unsigned int GetLength();

    // Setter
    virtual bool SetData(ElemType *data) = 0;

    virtual bool SetData(ElemType data, unsigned int index) = 0;

    bool SetLength();

    bool SetLength(unsigned int length);

    // 成员方法
    void PrintData();

    bool Insert(ElemType elem);

    bool Insert(ElemType elem, unsigned int index);

    bool Insert(ElemType *elems, unsigned int index, unsigned int size);

    ElemType Delete();

    ElemType Delete(unsigned int index);

    ElemType *Delete(unsigned int index, unsigned int length);

    int Search(ElemType elem);

    unsigned int Min();

    unsigned int Max();

    void Reverse();

    unsigned int DeleteElem(ElemType elem);
};

Linear::Linear() {
    this->_length = 0;
}

unsigned int Linear::GetLength() {
    return this->_length;
}

bool Linear::SetLength() {
    this->_length++;
    return true;
}

bool Linear::SetLength(unsigned int length) {
    this->_length = length;
    return true;
}

void Linear::PrintData() {
    std::cout << "data:[";
    for (int i = 0; i < this->GetLength(); i++) {
        std::cout << this->GetData(i);
        if (i < this->GetLength() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

bool Linear::Insert(ElemType elem) {
    return this->Insert(elem, this->GetLength());
}

bool Linear::Insert(ElemType elem, unsigned int index) {
    auto *elems = new ElemType[1]{elem};
    return this->Insert(elems, index, 1);
}

bool Linear::Insert(ElemType *elems, unsigned int index, unsigned int size) {
    if (index > this->GetLength()) {
        std::cout << "[Linear::Insert]:index " << index << " > max size " << this->GetLength() << std::endl;
        return false;
    }
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

ElemType Linear::Delete() {
    ElemType *elems = this->Delete(this->GetLength() - 1, 1);
    return elems == nullptr ? (ElemType) NULL : elems[0];
}

ElemType Linear::Delete(unsigned int index) {
    ElemType *elems = this->Delete(index, 1);
    return elems == nullptr ? (ElemType) NULL : elems[0];
}

ElemType *Linear::Delete(unsigned int index, unsigned int length) {
    auto *result = new ElemType[length];
    if (index + length > this->GetLength()) {
        std::cout << "[Linear::Delete]:data " << index + length << " > length" << this->GetLength() << std::endl;
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

int Linear::Search(ElemType elem) {
    return 0;
}

unsigned int Linear::Min() {
    return 0;
}

unsigned int Linear::Max() {
    return 0;
}

void Linear::Reverse() {

}

unsigned int Linear::DeleteElem(ElemType elem) {
    return 0;
}

