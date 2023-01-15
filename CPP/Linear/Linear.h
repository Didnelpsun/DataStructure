// 线性结构
#include "../Header/Constant.h"

class Linear {
private:
    // 私有成员
    unsigned int _length = 0;
public:
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
    virtual void PrintData();

    virtual bool Insert(ElemType elem);

    virtual bool Insert(ElemType elem, unsigned int index);

    virtual bool Insert(ElemType *elems, unsigned int index, unsigned int size);

    virtual ElemType Delete();

    virtual ElemType Delete(unsigned int index);

    virtual ElemType *Delete(unsigned int index, unsigned int length);

    virtual unsigned int DeleteElem(ElemType elem);

    virtual int Search(ElemType elem);

    virtual unsigned int Min();

    virtual unsigned int Max();

    virtual void Reverse();

    virtual void Rotate(int step) = 0;
};

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
        std::cout << "[Linear::Insert]:index " << index << " > length " << this->GetLength() << std::endl;
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

unsigned int Linear::DeleteElem(ElemType elem) {
    // 删除指定值后索引偏移值，即出现次数
    int dev = 0;
    for (int i = 0; i < this->GetLength(); i++) {
        // 如果不等就证明该位置的值要保留
        if (this->GetData(i) != elem) {
            // 如果前面不存在指定值就证明没有要删除的
            // 如果不等于0证明要删除部分元素，从而前移
            if (dev != 0)
                this->SetData(this->GetData(i), i - dev);
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

int Linear::Search(ElemType elem) {
    for (int i = 0; i < this->GetLength(); i++) {
        if (this->GetData(i) == elem)
            return i;
    }
    std::cout << "[Linear::Search]:can't find elem value = " << elem << std::endl;
    return -1;
}

unsigned int Linear::Min() {
    int min = 0;
    for (int i = 0; i < this->GetLength(); i++) {
        if (this->GetData(min) > this->GetData(i))
            min = i;
    }
    return min;
}

unsigned int Linear::Max() {
    int max = 0;
    for (int i = 0; i < this->GetLength(); i++) {
        if (this->GetData(max) < this->GetData(i))
            max = i;
    }
    return max;
}

void Linear::Reverse() {
    ElemType temp;
    for (int i = 0; i < this->GetLength() / 2; i++) {
        temp = this->GetData(i);
        this->SetData(this->GetData(this->GetLength() - i - 1), i);
        this->SetData(temp, this->GetLength() - i - 1);
    }
}

