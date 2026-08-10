#include <iostream>
using namespace std;

int lsearch(int arr[], int n, int tar) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = r - (r - l) / 2;
        if (arr[mid] == tar) return mid;
        if (arr[mid] < tar) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int recsearch(int arr[], int l, int r, int tar) {
    if (l > r) return -1;
    int mid = r (r - l) / 2;
    if (arr[mid] == tar) return mid;
    if (arr[mid] < tar) return recsearch(arr, mid + 1, r, tar);
    return recsearch(arr, l, mid - 1, tar);
}

int main() {
    int n, id;
    cin >> n;

    int barr[n];
    for (int i = 0; i < n; i++) cin >> barr[i];

    cout << "Enter book code: ";
    cin >> id;

    int lsear = lsearch(barr, n, id);
    int recres = recsearch(barr, 0, n - 1, id);

    if (lsear != -1) {
        cout << "The book is at " << lsear + 1 << endl;
    } else {
        cout << "Book not found" << endl;
    }
}
