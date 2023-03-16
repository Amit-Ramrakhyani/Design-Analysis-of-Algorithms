#include <iostream>
using namespace std;

int main(){
    int flag=0;
    int count=0;
    int arr[10] = {4, 6, 1, 8, 3, 7, 2, 0, 9, 5};
    for(int i=0; i<9; i++){
        for(int j=0; j<9-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=1;        
            }
            cout << ++count << " ";
        }
        if(flag==0){
            break;
        }
    }

    cout << endl << "Sorted array is: ";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}