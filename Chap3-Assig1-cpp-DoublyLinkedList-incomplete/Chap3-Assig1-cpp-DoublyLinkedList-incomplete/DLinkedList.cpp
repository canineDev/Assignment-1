#include <iostream>
#include "DLinkedList.h"

using namespace std;

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->right = trailer;
    trailer->left = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const {
    return (header->right == trailer) && (trailer->left == header);
}

const Ele& DLinkedList::front() const {
    return header->right->ele;
}

const Ele& DLinkedList::back() const {
    return trailer->left->ele;
}

void DLinkedList::addBefore(DNode* v, const Ele& e) { // add before v
    DNode* u = new DNode;
    u->ele = e;
    u->right = v;
    u->left = v->left;
    v->left->right = u;
    v->left = u;
}

DNode* DLinkedList::findNode(const Ele& e) {
    DNode* temp = header->right;
    while (temp != trailer && temp->ele != e) {
        temp = temp->right;
    }
    return (temp != trailer) ? temp : nullptr; // Return nullptr if not found
}

void DLinkedList::addFront(const Ele& e) {
    addBefore(header->right, e);
}

void DLinkedList::remove(DNode* v) {
    DNode* u = v->left;
    DNode* w = v->right;
    u->right = w;
    w->left = u;
    delete v;
}

/*
Find the first occurrence of the specified element (element) in
the list. Return an integer indicating the position of the element found in the
list containing the element if found, otherwise return -1. If the element is
found, print a message indicating its position in the list.
*/

int DLinkedList::find(const Ele& e){
    DNode* temp = header->right;    // Start at head
    int pos = 1;                    // Position, using 1 based indexing

    while(temp != trailer){
        if(temp->ele == e){
            cout << e << " found at position " << pos << endl;
            return pos;
        }
        temp = temp->right;         // Advance node
        ++pos;
    }
    return -1;  // Element is not found
}

/*
 Insert a new element (newElement) after a given element
(existingElement). If the existingElement is not found, print a suitable
message.
*/

void DLinkedList::insertAfter(DNode* v, const Ele& e){
    if(v == nullptr || v == trailer){
        cout << "Unable to insert after the current element. Please check input." << endl;  // Can't insert, maybe doesn't exist?
        return;
    }

    DNode* buf = new DNode; // New node, serves as buffer
    buf->ele = e;           // Place new node between v and the next node
    buf->right = v->right;
    buf->left = v;
    v->right->left = buf;
    v->right = buf;
}

void DLinkedList::removeFront() {
    remove(header->right);
}

void DLinkedList::printList() const {
    DNode* temp = header->right;

    if (temp == trailer) {  // List is empty if header's right points to trailer
        cout << "List is empty" << endl;
        return;
    }

    while (temp != trailer) {
        cout << temp->ele << endl;
        temp = temp->right;
    }
}

