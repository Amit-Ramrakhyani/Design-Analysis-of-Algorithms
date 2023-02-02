#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, n1, n2, sum=0, count=0;
    cout << "Number: ";
    cin >> n;
    n1 = n; 
    n2 = n;
    int len = n?0:1; 
    while (n1) { len++; n1/=10; }
    
    while(n2){
        count++;
        int temp = n2%10;
        sum += pow(temp, len);
        n2/=10;
        cout << count;
    }

    if(n == sum)
        cout << "\nNumber is armstrong!";
    else
        cout << "\nNumber is not armstrong!";
    
    return 0;
}