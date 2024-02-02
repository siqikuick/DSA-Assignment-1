#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template <class T>
void Print(vector<T>& vec, string s){
    cout << s << ": [" << flush;
    for (size_t i = 0; i < vec.size(); i++){
        cout << vec[i] << flush;
        if (i < vec.size() - 1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void Merge(vector<double>& A, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    vector<double> B(high + 1);
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void RecursiveMergeSort(vector<double>& A, int low, int high){
    if (low < high){
        int mid = low + (high - low) / 2;
        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements to sort: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<double> A(n);
    cout << "Enter " << n << " numbers (values can be double):" << endl;
    for (int i = 0; i < n; i++) {
        while (!(cin >> A[i])) {
            cout << "Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    Print(A, "A");
    RecursiveMergeSort(A, 0, n - 1);
    Print(A, "Sorted A");

    return 0;
}

