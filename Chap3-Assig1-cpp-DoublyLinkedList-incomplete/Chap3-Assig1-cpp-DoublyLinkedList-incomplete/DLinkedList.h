#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H 1

using namespace std;

typedef string Ele;

class DNode {
private:
    Ele ele;
    DNode* left;
    DNode* right;
    friend class DLinkedList;
};

class DLinkedList {
private:
    DNode* header;
    DNode* trailer;
protected:

public:
    DLinkedList();
    ~DLinkedList();
    bool empty() const;
    const Ele& front() const;
    const Ele& back() const;
    DNode* findNode(const Ele& e);
    void addFront(const Ele& e);
    void removeFront();
    void printList() const;
    void addBefore(DNode* v, const Ele& e);
    void remove(DNode* v);
    int find(const Ele& e);
    void insertAfter(const Ele& existingElement, const Ele& newElement);
    void reverse();
    void addBack(const Ele& e);
    void removeBack();
    friend class DLinkedListTest;
};

#endif