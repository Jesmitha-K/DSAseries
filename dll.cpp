#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void traverse(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void addBegin(Node*& head, int val) {
    Node* newNode = new Node(val);

    
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

void addEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void addMiddle(Node*& head, int pos, int val) {
    if (pos <= 1 || head == nullptr) {
        addBegin(head, val);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(val);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void delBegin(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}

void delEnd(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void delMiddle(Node*& head, int pos) {
    if (head == nullptr || pos <= 0) return;

    if (pos == 1) {
        delBegin(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
}

int main() {
    Node* head = nullptr;

    addBegin(head, 20);
    addBegin(head, 10);

    addEnd(head, 30);
    addEnd(head, 40);

    traverse(head);      

    addMiddle(head, 3, 25);
    traverse(head);     

    delBegin(head);
    traverse(head);      

    delEnd(head);
    traverse(head);      

    delMiddle(head, 2);
    traverse(head);      

    return 0;
}