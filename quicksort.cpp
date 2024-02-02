#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

template <class T>
void Print(const vector<T>& vec, const string& s) {
    cout << s << ": [";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template <class T>
int partition(vector<T>& A, int low, int high) {
    T pivot = A[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (A[i] < pivot);
        
        do {
            j--;
        } while (A[j] > pivot);

        if (i >= j) return j;

        swap(A[i], A[j]);
    }
}

template <class T>
void QuickSort(vector<T>& A, int low, int high) {
    if (low < high) {
        int j = partition(A, low, high);
        QuickSort(A, low, j);
        QuickSort(A, j + 1, high);
    }
}

int main() {
    cout << "Enter the number of values to sort (a positive integer): ";
    size_t n;
    while (!(cin >> n) || n <= 0) {
        cout << "Please enter a valid positive integer: ";
        cin.clear(); // Clear the error flag.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input.
    }

    vector<double> values(n);
    cout << "Enter " << n << " numbers (values can be double):" << endl;
    for (size_t i = 0; i < n; i++) {
        while (!(cin >> values[i])) {
            cout << "Invalid input, please enter a number: ";
            cin.clear(); // Clear the error flag.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input.
        }
    }

    Print(values, "Before Sorting");
    QuickSort(values, 0, static_cast<int>(values.size()) - 1); // Explicit cast here
    Print(values, "After Sorting");

    return 0;
}
