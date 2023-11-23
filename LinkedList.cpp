// @author Kondakov N

#include <iostream>
#include "LinkedList.h"


int main() {

    // создаем лист
    LinkedList<int> list;

    list.AddInHead(1);
    list.AddInTail(9);
    list.AddInTail(5);
    list.AddInTail(11);
    list.AddInHead(6);

    list.PrintList();

   


    list.SearchNode(1);
    list.SearchNode(55);

    // удаление 9 из списка
    list.RemoveNode(9);
    list.PrintList();

    // очиска всего списка
    list.ClearList();


}
