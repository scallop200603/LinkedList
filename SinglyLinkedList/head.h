#include <iostream>

using namespace std;

struct Node
{
    const char* element;
    Node* next;
    Node(const char* s, Node* n)
    {
        element = s;
        next = n;
    }
    Node(){}
    ~Node()
    {
        cerr << "Destructor of " << element << endl;
    }
};
struct LinkedListWithTail
{
    Node* head;
    Node* tail;
    LinkedListWithTail()
    {
        head = nullptr;
        tail = nullptr;
    }
    void addFirst(const char* s);
    void print();
    void addLast(const char* s);
    const char* removeFirst();
    const char* removeLast();
};
struct LinkedList
{
    Node* head;
    int size;
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }
    Node* addFirst(const char* s);
    void free(Node* node)
    {
        if(node != nullptr)
        {
            cerr << "Free " << node->element << endl;
            free(node->next);
            delete node;
        }
    }
    ~LinkedList()
    {
        cerr << "Destructor of LinkedList" << endl;
        free(head);
    }
    void print();
    const char* removeFirst();
    Node* addLast(const char* s);
    Node* insertAfter(const char* s, Node* node);
    void remove(Node* node);
    Node* Search(const char* s, Node* node);
    Node* search(const char* s);
};
