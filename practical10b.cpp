
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> h[10];
    int n, x;
    cout << "Enter number of books: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> x;
        int pos = x % 10;
        h[pos].push_back(x);
        cout << "Book added to shelf " << pos << endl;
    }
    cout << "\nFinal Shelf Contents:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (h[i].empty()) {
            cout << "Empty";
        } else {
            for (int j = 0; j < h[i].size(); j++) {
                cout << h[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
