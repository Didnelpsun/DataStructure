// 单链表结点
#include "../Header/Constant.h"

class LinkListNode {
// 私有成员
private:
    ElemType _data;
    LinkListNode *_next;
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

LinkListNode::LinkListNode() {
    this->_next = nullptr;
}

LinkListNode::LinkListNode(ElemType data) {
    this->_data = data;
    this->_next = nullptr;
}

LinkListNode::LinkListNode(ElemType data, LinkListNode *next) {
    this->_data = data;
    this->_next = next;
}

ElemType LinkListNode::GetData() {
    return this->_data;
}

LinkListNode *LinkListNode::GetNext() {
    return this->_next;
}

bool LinkListNode::SetData(ElemType data) {
    this->_data = data;
    return true;
}

bool LinkListNode::SetNext(LinkListNode *next) {

    if (next != nullptr) {
        this->_next = next;
        return true;
    }
    std::cout << "[LinkListNode::SetNext]:next is null" << std::endl;
    return false;
}