#include "LinkList.h"

void LinkListTest() {
    LinkList list;
    int *data = new int[5]{1, 2, 3, 4, 5};
    list.SetLength(5);
    list.SetData(data);
    list.PrintData();
    int *d = new int[3]{2, 3, 2};
    list.Insert(d, 2, 3);
    //list.PrintData();
    //ElemType *result = list.Delete(2, 2);
    //list.PrintData();
    //std::cout << "delete data:[";
    //for (int i = 0; i < 2; i++)
    //    std::cout << result[i] << " ";
    //std::cout << "]" << std::endl;
    //std::cout << "min:" << list.Min() << std::endl << "max:" << list.Max() << std::endl;
    //list.Reverse();
    //std::cout << "reverse->";
    //list.PrintData();
    //std::cout <<  "2 appear times:" << list.DeleteElem(2) << std::endl;
    //list.PrintData();
    //list.Rotate(2);
    //list.PrintData();
}
