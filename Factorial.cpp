#include <iostream>
using namespace std;

int main(){
    int n, fac=1, count=0;
    cout << "Number: ";
    cin >> n;

    if(n==0){
        count++;
        cout << count;
        cout << endl << fac;
        return 0;
    }

    for(int i=1; i<=n; i++){
        fac*=i;
        count++;
        cout << count << " ";
    }
    cout << endl << "Factorial of given number is: " << fac;
    return 0;
}