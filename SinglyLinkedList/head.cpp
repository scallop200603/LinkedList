#include <iostream>
#include "head.h"
#include <cstring>

using namespace std;

Node* LinkedList::search(const char* s)
{
    return Search(s, head);
}
Node* LinkedList::Search(const char* s, Node* node)
{
    if(node == nullptr) return nullptr;
    if(strcmp(s, node->element) == 0) return node;
    return Search(s, node->next);
}
void LinkedList::remove(Node* node)
{
    if(node == head)
    {
        removeFirst();
        return;
    }
    if(node == nullptr) return;
    Node* prev = head;
    while(prev->next != node && prev->next != nullptr)
    {
        prev = prev->next;
    }
    if(prev->next == nullptr) return;
    prev->next = node->next;
    delete node;
}
Node* LinkedList::insertAfter(const char* s, Node* node)
{
    if(node == nullptr) return nullptr;
    Node* newNode = new Node;
    Node* nextNode = node->next;
    newNode->next = nextNode;
    newNode->element = s;
    node->next = newNode;
    return newNode;
}
Node* LinkedList::addFirst(const char* s)
{
    Node* newNode = new Node;
    newNode->element = s;
    newNode->next = head;
    head = newNode;
    return newNode;
}
void LinkedList::print()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->element << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
const char* LinkedList::removeFirst()
{
    if(head == nullptr) return nullptr;
    Node* old = head;
    head = head->next;
    const char* s = old->element;
    delete old;
    return s;
}
Node* LinkedList::addLast(const char* s)
{
    Node* newNode = new Node;
    newNode->element = s;
    newNode->next = nullptr;
    if(head == nullptr) head = newNode;
    else
    {
        Node* tail = head;
        while(tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
    return newNode;
}
const char* LinkedListWithTail::removeLast()
{
    if(head != tail)
    {
        Node* ultimate = head;
        while(ultimate->next != tail) ultimate = ultimate->next;
        const char* s = tail->element;
        delete tail;
        tail = ultimate;
        tail->next = nullptr;
        return s;
    }
    else if(head != nullptr)
    {
        const char* oldData = tail->element;
        delete tail;
        head = nullptr;
        tail = nullptr;
        return oldData;
    }
    else{
        return nullptr;
    }
}
const char* LinkedListWithTail::removeFirst()
{
    if(head == nullptr) return nullptr;
    Node* p = head;
    head = head->next;
    const char* s = p->element;
    delete p;
    return s;
}
void LinkedListWithTail::addLast(const char* s)
{
    Node* newNode = new Node;
    newNode->element = s;
    newNode->next = nullptr;
    if(head == nullptr) head = newNode;
    else tail->next = newNode;
    tail = newNode;
}
void LinkedListWithTail::addFirst(const char* s)
{
    Node* newNode = new Node;
    newNode->element = s;
    newNode->next = head;
    head = newNode;
    if(tail == nullptr) tail = head;
}
void LinkedListWithTail::print()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->element << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
