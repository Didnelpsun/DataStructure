// 线性结构
#include "../Header/constant.h"

class Linear {
private:
    // 私有成员
    unsigned int _length{};
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
    virtual void PrintData() = 0;

    virtual bool Insert(ElemType elem) = 0;

    virtual bool Insert(ElemType elem, unsigned int index) = 0;

    virtual bool Insert(ElemType *elems, unsigned int index, unsigned int size) = 0;

    virtual ElemType Delete() = 0;

    virtual ElemType Delete(unsigned int index) = 0;

    virtual ElemType* Delete(unsigned int index, unsigned int length) = 0;

    virtual int Search(ElemType elem) = 0;

    virtual unsigned int Min() = 0;

    virtual unsigned int Max() = 0;

    virtual void Reverse() = 0;

    virtual unsigned int DeleteElem(ElemType elem) = 0;
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

