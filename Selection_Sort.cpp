#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int min, minIndex, count=0;
    int arr[12] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 11};
    for(int i=0; i<11; i++){
        min = arr[i];
        minIndex = i;
        for(int j=i+1; j<12; j++){
            if(arr[minIndex] > arr[j]){
                min = arr[j];
                minIndex = j;
            }
            cout << ++count;
        }
        swap(arr[minIndex], arr[i]);
    }

    for(int i=0; i<12; i++){
        cout << endl << arr[i];
    }
    
    return 0;
}