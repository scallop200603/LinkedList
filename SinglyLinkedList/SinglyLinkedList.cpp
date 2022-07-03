#include <iostream>
#include <string.h>
#include "head.h"

using namespace std;

int main()
{
    LinkedList* list = new LinkedList;
    list->addFirst("Paris");
    list->addLast("London");
    list->addFirst("Tokyo");
    list->print();
    Node* find = list->search("London");
    cerr << "Found " << find->element << "!" << endl;
    find = list->search("Paris");
    cerr << "Found " << find->element << "!" << endl;
    find = list->search("Tokyo");
    cerr << "Found " << find->element << "!" << endl;
    find = list->search("Rome");
    cerr << "Found " << find << "!" << endl;
    delete list;

    cout << "Haha";
    return 0;
}



