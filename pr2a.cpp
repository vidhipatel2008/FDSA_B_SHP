#include <iostream>
using namespace std;

int search(int arr[], int n, int t) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == t) return i;
    }
    return -1;
}
int recsearch(int arr[], int n, int t, int indx) {
    if (indx >= n) return -1;
    if (arr[indx] == t) return indx;
    return recsearch(arr, n, t, indx + 1);
}

int main() {
    int n, ln;
    cin >> n;
    int licarr[n];
    for (int i = 0; i < n; i++) {
        cin >> licarr[i];
    }

    cout << "Enter the license number: ";
    cin >> ln;

    int nors = search(licarr, n, ln);
    int recus = recsearch(licarr, n, ln, 0);
    if (nors != -1) {
        cout << "The car is at " << nors + 1 << endl;
    } else {
        cout << "Not found" << endl;
    }
}
