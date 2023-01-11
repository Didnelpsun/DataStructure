// 单链表
#include "Linear.h"
#include "LinkListNode.h"

class LinkList : public Linear {
// 私有成员
private:
    LinkListNode *_node{};
public:
    // 构造函数
    LinkList();

    explicit LinkList(LinkListNode *data);

    // Getter
    LinkListNode *GetNode();

    LinkListNode GetNode(unsigned int index);

    ElemType GetData(unsigned int index) override;

    // Setter
    bool SetNode(LinkListNode *node);

    bool SetNode(LinkListNode node, unsigned int index);

    bool SetData(ElemType data, unsigned int index) override;
};

LinkList::LinkList() {
    this->_node = nullptr;
}

LinkList::LinkList(LinkListNode *node) {
    this->_node = node;
}

LinkListNode *LinkList::GetNode() {
    return this->_node;
}

LinkListNode LinkList::GetNode(unsigned int index) {
    unsigned int i = 0;
    LinkListNode *node = this->GetNode();
    while (node->GetNext() != nullptr) {
        if (i == index)
            return (LinkListNode &&) node;
        node = node->GetNext();
        i++;
    }
    std::cout << "[LinkList::GetNode]:" << "can't find node index = " << index << std::endl;
    return {};
}

ElemType LinkList::GetData(unsigned int index) {
    return this->GetNode(index).GetData();
}

bool LinkList::SetNode(LinkListNode *node) {
    if (node != nullptr) {
        this->_node = node;
        return true;
    }
    std::cout << "[LinkList::SetNode]:node is null" << std::endl;
    return false;
}

bool LinkList::SetNode(LinkListNode node, unsigned int index) {
    return false;
}

bool LinkList::SetData(ElemType data, unsigned int index) {
    return false;
}




