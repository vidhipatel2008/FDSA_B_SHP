#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertPosition(int value, int pos) {
    if (pos <= 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    insertBeginning(101);
    display();

    insertEnd(102);
    display();

    insertEnd(103);
    display();

    insertPosition(99, 2);
    display();

    insertPosition(104, 5);
    display();

    insertPosition(200, 10);
    display();

    return 0;
}
