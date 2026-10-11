
#include <iostream>
using namespace std;
int main() {
    int h[10];
    int n, x;
    for (int i = 0; i < 10; i++) {
        h[i] = -1;
    }
    cout << "Enter number of vehicles: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter vehicle registration number: ";
        cin >> x;
        int pos = x % 10;
        int count = 0;
        while (h[pos] != -1 && count < 10) {
            pos = (pos + 1) % 10;
            count++;
        }
        if (count == 10) {
            cout << "Parking lot is full. Vehicle cannot be parked.\n";
        } else {
            h[pos] = x;
            cout << "Vehicle parked at slot " << pos << endl;
        }
    }
    cout << "\nFinal Parking Slots:\n";
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
