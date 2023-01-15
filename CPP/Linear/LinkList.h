// 单链表
#include "Linear.h"
#include "LinkListNode.h"

class LinkList : public Linear {
// 私有成员
private:
    LinkListNode *_node = nullptr;
public:
    // 构造函数
    LinkList();

    explicit LinkList(LinkListNode *node);

    // Getter
    LinkListNode *GetNode();

    LinkListNode *GetNode(unsigned int index);

    ElemType *GetData() override;

    ElemType GetData(unsigned int index) override;

    // Setter
    bool SetNode(LinkListNode *node);

    bool SetNode(LinkListNode node, unsigned int index);

    bool SetData(ElemType *data) override;

    bool SetData(ElemType data, unsigned int index) override;

    // 成员函数
    void PrintLinkList();

    void Rotate(int step) override;
};

LinkList::LinkList() = default;

LinkList::LinkList(LinkListNode *node) {
    this->_node = node;
}

LinkListNode *LinkList::GetNode() {
    return this->_node;
}

LinkListNode *LinkList::GetNode(unsigned int index) {
    if (index >= this->GetLength()) {
        std::cout << "[LinkList::GetNode]:index " << index << " > length " << this->GetLength() << std::endl;
        return nullptr;
    }
    unsigned int i = 0;
    LinkListNode *node = this->GetNode();
    if (node != nullptr) {
        while (node->GetNext() != nullptr) {
            if (i == index)
                return node;
            node = node->GetNext();
            i++;
        }
        if (i == index)
            return node;
        node = node->GetNext();
        i++;
    }
    // 如果i<length，则证明需要插入结点
    LinkListNode* new_node;
    while(i<this->GetLength()){
        if (this->GetNode() == nullptr) {
            this->SetNode(new LinkListNode());
            node = this->GetNode();
        }
        else {
            node->SetNext(new LinkListNode());
            node = node->GetNext();
        }
        if (i == index)
            new_node = node;
        i++;
    }
    return new_node;
}

ElemType *LinkList::GetData() {
    auto *data = new ElemType[this->GetLength()];
    for (int i = 0; i < this->GetLength(); i++)
        data[i] = this->GetData(i);
    return data;
}

ElemType LinkList::GetData(unsigned int index) {
    return this->GetNode(index)->GetData();
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
    LinkListNode *pre = nullptr;
    LinkListNode *current = this->GetNode();
    if (index > this->GetLength()) {
        std::cout << "[LinkList::SetNode]:index " << index << " > length " << this->GetLength() << std::endl;
        return false;
    }
    unsigned int i = 0;
    while (current != nullptr) {
        if (i == index) {
            if (pre != nullptr)
                pre->SetNext(&node);
            node.SetNext(current->GetNext());
            return true;
        }
        pre = current;
        current = current->GetNext();
        i++;
    }
    return false;
}

bool LinkList::SetData(ElemType *data) {
    for (int i = 0; i < this->GetLength(); i++) {
        if(!this->SetData(data[i], i))
            return false;
    }
    return true;
}

bool LinkList::SetData(ElemType data, unsigned int index) {
    LinkListNode *node = this->GetNode(index);
    if (node == nullptr) {
        std::cout << "[LinkList::SetData]:index " << index << " > length " << this->GetLength() << std::endl;
        return false;
    }
    node->SetData(data);
    return true;
}

void LinkList::PrintLinkList() {
    this->PrintData();
    std::cout << "length:" << this->GetLength() << std::endl;
}

void LinkList::Rotate(int step) {

}
