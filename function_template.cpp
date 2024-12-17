#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int n;

template <class T>
void selection(T A[]) {
    int i, j, Min;
    T temp;

    for (i = 0; i < n - 1; i++) {
        Min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[Min]) {
                Min = j;
            }
        }
        temp = A[i];
        A[i] = A[Min];
        A[Min] = temp;
    }

    cout << "The sorted list is: ";
    for (i = 0; i < n; i++) {
        cout << "  " << A[i];
    }
    cout << endl;
}

int main() {
    int i, A[MAX_SIZE];
    float B[MAX_SIZE];

    cout << "**Selection Sort**"<<endl;

    cout << "Handling integer elements "<<endl;
    cout << "How many elements are there? "<<endl;
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Error: Maximum size exceeded. ";
        return 1;
    }

    cout << "Enter the integer elements: ";
    for (i = 0; i < n; i++) {
        cin >> A[i];
    }
    selection(A);
    cout << "Handling floats elements "<<endl;
    cout << "How many elements are there? ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Error: Maximum size exceeded. ";
        return 1;
    }

    cout << "Enter the float elements: ";
    for (i = 0; i < n; i++) {
        cin >> B[i];
    }
    selection(B);

    return 0;
}