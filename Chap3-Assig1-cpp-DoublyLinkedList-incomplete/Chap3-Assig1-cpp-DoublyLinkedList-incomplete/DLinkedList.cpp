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
    DNode* buf = header->right;     // Start at head
    int pos = 1;                    // Position, using 1 based indexing

    while(buf != trailer){
        if(buf->ele == e){
            cout << e << " found at position " << pos << endl;
            return pos;
        }
        buf = buf->right;           // Advance node
        ++pos;
    }
    cout<<"Couldn't find element";
    return -1;  // Element is not found
}

/*
 Insert a new element (newElement) after a given element
(existingElement). If the existingElement is not found, print a suitable
message.
*/

void DLinkedList::insertAfter(const Ele& existingElement, const Ele& newElement){
    DNode* v = findNode(existingElement);   // Find the node containing existingElement

    if (v == nullptr) {
        cout << "Element \"" << existingElement << "\" not found. Cannot insert \"" 
             << newElement << "\" after it." << endl;
        return;
    }

    DNode* e = new DNode;   // Create new node
    e->ele = newElement;

    e->right = v->right;    // Place e between v and v->right
    e->left  = v;
    v->right->left = e;
    v->right = e;
}

/*
Reverse the order of elements in the list. This operation should
modify the list in place so that the last element now becomes the first
element, second last becomes the second element and so on in the modified
list. When printed by the printList() function it print the list in reverse order.
*/

void DLinkedList::reverse(){
    DNode* current = header;

    while (current != nullptr) {        // Traverse list
        DNode* temp = current->left;    // Swap left node with right node
        current->left = current->right;
        current->right = temp;
        current = current->left;    // Move forward
    }

    DNode* temp = header;   // Swap header and trailer
    header = trailer;
    trailer = temp;
}

/*
add a new element (newElement) at the back of the list).
*/

void DLinkedList::addBack(const Ele& e){
    addBefore(trailer, e);  // Simply call existing function with trailer node
}

/*
remove the element from the back of the list.
*/

void DLinkedList::removeBack() {
    if (!empty()) {
        remove(trailer->left);
    } else {
        cout << "List is empty, unable to remove back element." << endl;
    }
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

