#include <iostream>
using namespace std;

int main(){
    int n, count=0;
    int arr[10] = {5, 4, 9, 7, 3, 2, 8, 0, 1, 6};
    cout << "Enter number to be searched: ";
    cin >> n;

    for(int i=0; i<10; i++){
        count++;
        cout << count << " ";
        if(n == arr[i]){
            cout << "\nElement found!";
            return 0;
        }
    }
    cout << "\nElement not found!";
    return 0;
}