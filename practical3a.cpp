#include <iostream>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a[i], a[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main() {
    int marks[] = {78, 45, 92, 66, 35, 88};
    int n = sizeof(marks) / sizeof(marks[0]);

    int bubble[6], selection[6], insertion[6];

    for (int i = 0; i < n; i++) {
        bubble[i] = marks[i];
        selection[i] = marks[i];
        insertion[i] = marks[i];
    }

    bubbleSort(bubble, n);
    selectionSort(selection, n);
    insertionSort(insertion, n);

    cout << "Original Marks: ";
    printArray(marks, n);

    cout << "Bubble Sort: ";
    printArray(bubble, n);

    cout << "Selection Sort: ";
    printArray(selection, n);

    cout << "Insertion Sort: ";
    printArray(insertion, n);

    cout << "\nHow they work:\n";
    cout << "Bubble Sort: Compares adjacent marks and swaps them when they are in the wrong order.\n";
    cout << "Selection Sort: Finds the smallest mark and places it at the correct position.\n";
    cout << "Insertion Sort: Takes one mark at a time and inserts it into the correct position.\n";

    cout << "\nIf the marks are already sorted, Insertion Sort finishes fastest because it only checks\n";
    cout << "each element and does not need to shift or swap elements.\n";

    return 0;
}

