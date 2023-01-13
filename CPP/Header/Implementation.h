// 继承实现类

class Implementation {
private:
    // 实现类名称
    char *_name{};
    // 类名称长度
    unsigned int _name_length{};
    // 属性数
    unsigned int _attribute{};
    // 方法数
    unsigned int _method{};
public:
    // 构造函数
    Implementation() {
        this->_name = nullptr;
        this->_name_length = 0;
        this->_attribute = 0;
        this->_method = 0;
    }

    Implementation(char *name, unsigned int nameLength) {
        this->_name = name;
        this->_name_length = nameLength;
        this->_attribute = 0;
        this->_method = 0;
    }

    Implementation(char *name, unsigned int nameLength, unsigned int attribute, unsigned int method) {
        this->_name = name;
        this->_name_length = nameLength;
        this->_attribute = attribute;
        this->_method = method;
    }

    // Getter
    char *GetName() {
        return _name;
    }

    unsigned int GetNameLength() {
        return _name_length;
    }

    unsigned int GetAttribute() {
        return _attribute;
    }

    unsigned int GetMethod() {
        return _method;
    }

    // Setter
    void SetName(char *name) {
        _name = name;
    }

    void SetNameLength(unsigned int nameLength) {
        _name_length = nameLength;
    }

    void SetAttribute() {
        _attribute++;
    }

    void SetAttribute(unsigned int attribute) {
        _attribute = attribute;
    }

    void SetMethod() {
        _method++;
    }

    void SetMethod(unsigned int method) {
        _method = method;
    }
};