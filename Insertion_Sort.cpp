//insertion sort
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {4, 5, 1, 7, 9, 3, 8, 6, 2, 0};
    int key, j, count=0;
    for(int i=1; i<10; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
            cout << ++count << " ";
        }
        arr[j+1] = key;
    }

    cout << endl << "Sorted array is: ";
    for(int i=0; i<10; i++){
        cout << " " << arr[i];
    }
    return 0;
}
