#include <iostream>
using namespace std;
struct Node {
    int patient;
    Node* next;
};
int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, patient;
    do {
        cout << "\n1. Arrive";
        cout << "\n2. Attend";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter patient number: ";
            cin >> patient;
            Node* newNode = new Node;
            newNode->patient = patient;
            newNode->next = NULL;
            if (front == NULL) {
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            cout << "Patient added successfully.\n";
        }
        else if (choice == 2) {
            if (front == NULL) {
                cout << "Queue is empty. No patient to attend.\n";
            } else {
                Node* temp = front;
                cout << "Attended patient: " << front->patient << endl;
                front = front->next;
                if (front == NULL) {
                    rear = NULL;
                }
                delete temp;
            }
        }
        else if (choice == 3) {
            cout << "Program ended.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
        if (front == NULL) {
            cout << "Current front patient: None\n";
        } else {
            cout << "Current front patient: " << front->patient << endl;
        }
    } while (choice != 3);
    while (front != NULL) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    return 0;
}

