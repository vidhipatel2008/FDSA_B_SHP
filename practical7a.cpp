#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;
    int q[100];
    int front = -1, rear = -1;
    int choice, token;
    do {
        cout << "\n1. Join";
        cout << "\n2. Serve";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            if (rear == n - 1) {
                cout << "Queue is full. Cannot issue token.\n";
            } else {
                cout << "Enter token number: ";
                cin >> token;
                if (front == -1) {
                    front = 0;
                }
                rear++;
                q[rear] = token;
                cout << "Token added successfully.\n";
            }
        }
        else if (choice == 2) {
            if (front == -1) {
                cout << "Queue is empty. Cannot serve.\n";
            } else {
                cout << "Served token: " << q[front] << endl;
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front++;
                }
            }
        }
        else if (choice == 3) {
            cout << "Program ended.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
        if (front == -1) {
            cout << "Current front token: None\n";
        } else {
            cout << "Current front token: " << q[front] << endl;
        }
    } while (choice != 3);
    return 0;
}

