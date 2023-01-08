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

    [[nodiscard]] unsigned int GetLength() const;

    // Setter
    virtual bool SetData(ElemType *data) = 0;

    virtual bool SetData(unsigned int index, ElemType data) = 0;

    bool SetLength();

    bool SetLength(unsigned int length);

    virtual void printData() = 0;

    virtual bool Insert() = 0;

    virtual ElemType Delete(unsigned int index) = 0;

    virtual ElemType* Delete(unsigned int start, unsigned int end) = 0;
};

unsigned int Linear::GetLength() const {
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

