#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int M=1e9+7;
unsigned int factorial(int a) {
       int res = 1;
    for (int i = 2; i <= a; i++)
        res = res * i;
    return res;
}

int main () {
    double a,b,r;
    char op;

    cout<<"+ to Add, - to Subtract, * To Multiply, / To Divide, \
^ To Power, ! To Factorial\n\n";
    start: // THE BEGINING

    cin>>a; // 1ST NUMBER
    cin>>op; // OPERATOR
    // WHAT TO DO
    if (op=='!') r=factorial(a); 
    else {
         cin>>b;
         if (op=='+') r=a+b;
         if (op=='-') r=a-b;
         if (op=='*') r=a*b;
         if (op=='/') r=a/b;
         if (op=='^') r=pow(a,b);
         }
    //  RESULT
    cout<<"="<<r<<"\n";
    return 0;
}