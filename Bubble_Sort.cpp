#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int flag=0;
    int count=0;
    int arr[10] = {10, 6, 9, 4, 8, 2, 1, 3, 5, 7};
    for(int i=0; i<9; i++){
        for(int j=0; j<9-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag=1;        
            }
            cout << ++count;
        }
        if(flag==0){
            break;
        }
    }

    for(int i=0; i<10; i++){
        cout << endl << arr[i];
    }
    
    return 0;
}