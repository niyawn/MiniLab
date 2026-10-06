
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next; 
};

Node* createNode(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void addNode(Node*& head, Node*& tail, string data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void forwardTraversal(Node* head) {
    Node* current = head;
    cout << "Forward:\n";
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
    cout << endl;
}

void backwardTraversal(Node* tail) {
    Node* current = tail;
    cout << "Backward:\n";
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->prev;
    }
    cout << endl;

Node* insertAfter(Node*& tail, Node* current, const string& data) {
    if (current == nullptr) return nullptr;

    Node* newNode = createNode(data);
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        tail = newNode;        
    }
    current->next = newNode;

    return newNode;              
}
