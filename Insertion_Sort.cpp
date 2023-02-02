//insertion sort
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[10] = {10, 6, 9, 4, 8, 2, 1, 3, 5, 7};
    int key, j;
    for(int i=1; i<10; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i=0; i<10; i++){
        cout << endl << arr[i];
    }
    return 0;
}
