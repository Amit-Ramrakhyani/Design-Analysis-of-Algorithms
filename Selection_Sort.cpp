#include <iostream>
using namespace std;

int main(){
    int min, minIndex, count=0;
    int arr[10] = {5, 3, 7, 2, 0, 6, 9, 4, 8, 1};
    for(int i=0; i<10; i++){
        min = arr[i];
        minIndex = i;
        for(int j=i+1; j<10; j++){
            if(arr[minIndex] > arr[j]){
                min = arr[j];
                minIndex = j;
            }
            cout << ++count << " ";
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    cout << endl << "Sorted array is: ";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}