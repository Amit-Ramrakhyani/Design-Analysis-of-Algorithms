#include <iostream>
using namespace std;

int arr[100], farr[100], n;

void merge(int low, int mid, int high){
    int i = low, j = mid+1, k = low;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            farr[k] = arr[i];
            i++;
        }
        else{
            farr[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        farr[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        farr[k] = arr[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = farr[i];
    }
}

void mergeSort(int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);
        merge(low, mid, high);
    }
}

int main(){
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    mergeSort(0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    return 0;
}