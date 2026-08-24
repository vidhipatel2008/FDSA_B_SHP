#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

void deleteValue(int value) {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value not found" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void displayForward() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void displayReverse(Node* temp) {
    if (temp == NULL)
        return;

    displayReverse(temp->next);
    cout << temp->data << " ";
}

void reversePrint() {
    displayReverse(head);
    cout << endl;
}

int main() {
    insertEnd(101);
    insertEnd(102);
    insertEnd(103);
    insertEnd(104);
    insertEnd(105);

    cout << "Forward Queue: ";
    displayForward();

    deleteValue(103);

    cout << "After Deletion: ";
    displayForward();

    cout << "Reverse Queue: ";
    reversePrint();

    return 0;
}
