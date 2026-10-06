
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
void clearList(Node*& head, Node*& tail) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    addNode(head, tail, "Song A: Bohemian Rhapsody");
    addNode(head, tail, "Song B: The cure");
    addNode(head, tail, "Song C: Stop the wedding");
    addNode(head, tail, "Song D: Numb");
    addNode(head, tail, "Song E: Bring me to life");

    cout << "FULL LIST CREATION\n";
    forwardTraversal(head);

    cout << "TRAVERSALS\n";
    forwardTraversal(head); 
    backwardTraversal(tail); 

    cout << "INSERT IN THE MIDDLE\n";
    // cout << "Action: Inserting 'Song X: Dropdead' between Song B and Song C.\n";
    Node* current = head;
    while (current != nullptr && current->data != "Song B: The cure") {
        current = current->next;
    }
    insertAfter(tail, current, "Song X: Dropdead"); 
    
    cout << "\nAfter Insertion:\n";
    forwardTraversal(head);
    backwardTraversal(tail);

    cout << "PREDICT BEFORE RUNNING\n";
    // cout << "Prediction: If Song C (Stop the wedding) is deleted, Song X will connect directly to Song D.\n"; 

    cout << "DELETE A NODE\n";
    // cout << "Action: Deleting 'Song C: Stop the wedding'.\n"; 
    deleteNode(head, tail, "Song C: Stop the wedding"); 
    
    cout << "\nAfter Deletion:\n";
    forwardTraversal(head);
    backwardTraversal(tail);

    clearList(head, tail);
    return 0;
}
