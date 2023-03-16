#include <iostream>
#include <math.h>
using namespace std;

float r1, r2;
int a, b, c;
int p, q;
int n1, n2;
int c1, c2;

float delta(int a, int b, int c){
    return ((pow(b, 2)) - 4*a*c);
}

string roots(){
    float delta1;
    delta1 = delta(a, b, c);    
    if(delta1 > 0){
        r1 = (-b + sqrt(delta1)) / (2*a);
        r2 = (-b - sqrt(delta1)) / (2*a);
        return "Two roots: " + to_string(r1) + " and " + to_string(r2);
    }else if(delta1 == 0){
        r1 = (-b + sqrt(delta1)) / (2*a);
        r2 = r1;
        return "One root: " + to_string(r1);
    }else{
        return "No roots";
    }
}

string charEquation(){
    if(r1!=r2)
        return "Equation: c1(" + to_string(r1) + ")^n + c2(" + to_string(r2) + ")^n";
    else
        return "Equation: (c1 + n*c2)" + to_string(r2) + "^n";
}

string solution(){
    double a1 = pow(r1, n1);
    double b1 = pow(r2, n1);
    double a2 = pow(r1, n2);
    double b2 = pow(r2, n2);        
    if ((a1 * b2) - (b1 * a2) == 0){
        cout << "The system has no solution." << endl;
    }
    else{
        c1 = (((-p) * b2) - (b1 * (-q)))/((a2 * b1)-(b2 * a1));
        c2 = ((a2 * (-p)) - ((-q) * a1)) / ((a1 * b2) - (b1 * a2));
        if (r1!=r2){
            return "Equation: " + to_string(c1) + "(" + to_string(r1) + ")^n + " + to_string(c2) + "(" + to_string(r2) + ")^n";
        }
        else{
            return "Equation: (" + to_string(c1) + " + n*" + to_string(c2) + ")" + to_string(r1) + "^n";
        }
    }
    return NULL;
}


int main(){
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;
    cout << roots() << endl;
    cout << charEquation() << endl;
    cout << "Enter n, p for F(n) = p:  ";
    cin >> n1 >> p;
    cout << "Enter n, q for F(n) = q: ";
    cin >> n2 >> q;
    cout << solution() << endl;
    return 0;
}