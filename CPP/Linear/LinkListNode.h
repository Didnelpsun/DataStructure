// 单链表结点
#include "../Header/Constant.h"

class LinkListNode {
// 私有成员
private:
    ElemType _data = (ElemType) NULL;
    LinkListNode *_next = nullptr;
public:
    // 构造方法
    LinkListNode();

    explicit LinkListNode(ElemType data);

    LinkListNode(ElemType data, LinkListNode *next);

    // Getter
    ElemType GetData();

    LinkListNode *GetNext();

    // Setter
    bool SetData(ElemType data);

    bool SetNext(LinkListNode *next);
};

LinkListNode::LinkListNode() = default;

LinkListNode::LinkListNode(ElemType data) {
    this->_data = data;
    this->_next = nullptr;
}

LinkListNode::LinkListNode(ElemType data, LinkListNode *next) {
    this->_data = data;
    this->_next = next;
}

ElemType LinkListNode::GetData() {
    if (this == nullptr) {
        std::cout << "[LinkListNode::GetData]:this is null" << std::endl;
        return NULL;
    }
    return this->_data;
}

LinkListNode *LinkListNode::GetNext() {
    if (this == nullptr) {
        std::cout << "[LinkListNode::GetNext]:this is null" << std::endl;
        return nullptr;
    }
    return this->_next;
}

bool LinkListNode::SetData(ElemType data) {
    if (this == nullptr) {
        std::cout << "[LinkListNode::SetData]:this is null" << std::endl;
        return false;
    }
    this->_data = data;
    return true;
}

bool LinkListNode::SetNext(LinkListNode *next) {
    if (this == nullptr) {
        std::cout << "[LinkListNode::SetNext]:this is null" << std::endl;
        return false;
    }
    this->_next = next;
    return true;
}