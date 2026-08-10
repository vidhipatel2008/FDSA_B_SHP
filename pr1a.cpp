#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the no. of books borrowed: ";
    cin >> n;

    int bookid[n];
    for (int i = 0; i < n; i++) {
        cin >> bookid[i];
    }

    int count[n];

    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bookid[i] == bookid[j]) {
                count[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (count[i] > 1) {
            int alreadyPrinted = 0;
            for (int j = 0; j < i; j++) {
                if (bookid[i] == bookid[j]) {
                    alreadyPrinted = 1;
                    break;
                }
            }

            if (!alreadyPrinted) {
                cout << "Book ID: " << bookid[i] << endl;
            }
        }
    }


/*    for (int i = 0; i < n; i++) {
        if (count[i] > 1) {
            for (int j = 0; j < i; j++) {
                if (bookid[i] == bookid[j]) {
                    cout << "Book ID: " << bookid[i] << endl;
                    break;
                }
            }
        }
    }
        */
}
