#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int _data, Node* _prev, Node* _next)
    {
        data = _data;
        prev = _prev;
        next = _next;
    }
    Node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
};
struct DoublyLinkedList
{
    Node* head;
    Node* tail;
    DoublyLinkedList()
    {
        head = new Node;
        tail = new Node;
        head->data = 0;
        head->next = tail;
        head->prev = nullptr;
        tail->data = 0;
        tail->next = nullptr;
        tail->prev = head;
    }
    Node* insertLast(int x);
    Node* insertFirst(int x);
    void remove(Node* node);
    void print();
    void printReverse();
};
int main()
{
    DoublyLinkedList list;
    list.insertFirst(6);
    list.insertFirst(4);
    Node* node = list.insertFirst(7);
    list.insertFirst(2);
    list.insertLast(10);
    list.print();
    list.printReverse();
    list.remove(node);
    list.print();
    cout << "Hello" << endl;
    return 0;
}
void DoublyLinkedList::remove(Node* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}
Node* DoublyLinkedList::insertLast(int x)
{
    Node* newNode = new Node(x, tail->prev, tail);
    Node* temp = tail->prev;
    tail->prev = newNode;
    temp->next = newNode;
    return newNode;
}
Node* DoublyLinkedList::insertFirst(int x)
{
    Node* newNode = new Node(x, head, head->next);
    Node* temp = head->next;
    head->next = newNode;
    temp->prev = newNode;
    return newNode;
}
void DoublyLinkedList::printReverse()
{
    Node* p = tail->prev;
    while(p != head)
    {
        cout << p->data << "->";
        p = p->prev;
    }
    cout << endl;
}
void DoublyLinkedList::print()
{
    Node* p = head->next;
    while(p != tail)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}
