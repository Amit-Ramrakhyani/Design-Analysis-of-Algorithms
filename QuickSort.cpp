#include <iostream>
using namespace std;

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[last]);
    return i+1;
}

void QuickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        QuickSort(arr, first, pivot - 1);
        QuickSort(arr, pivot + 1, last-1);
    }
}

int main() {
    int arr[100], n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    QuickSort(arr, 0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    return 0;
}

