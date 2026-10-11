
#include <iostream>
using namespace std;
int main() {
    int h[10];
    int n, x;
    for (int i = 0; i < 10; i++) {
        h[i] = -1;
    }
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> x;
        int h1 = x % 10;
        int h2 = 7 - (x % 7);
        int pos;
        int j;
        for (j = 0; j < 10; j++) {
            pos = (h1 + j * h2) % 10;
            if (h[pos] == -1) {
                h[pos] = x;
                cout << "Student placed at slot " << pos << endl;
                break;
            }
        }
        if (j == 10) {
            cout << "Hash table is full. Student cannot be placed.\n";
        }
    }
    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (h[i] == -1) {
            cout << "Empty";
        } else {
            cout << h[i];
        }
        cout << endl;
    }
    return 0;
}
