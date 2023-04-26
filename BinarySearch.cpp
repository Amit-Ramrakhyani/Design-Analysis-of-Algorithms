#include <iostream>
using namespace std;

int BinarySearch (int arr[], int x, int size) {
    int first = 0, last = size-1, mid;
    while(first <= last) {
        mid = (first + last)/2;
        if (arr[mid] == x){
            return mid+1;
        }
        else if(arr[mid] > x) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    return 0;
}

int main() {
    int x, i;
    int arr[] = {2, 5, 6, 9, 10, 13, 17, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter number to be searched: ";
    cin >> x;

    if(i = BinarySearch(arr, x, size)) cout << "Number found at index " << i-1;
    else cout << "Number not found!"; 
}