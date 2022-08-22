#include<bits/stdc++.h>
using namespace std;

// Program 1 (Sum of N natural numbers using Recursion)

int sumN(int n){
    if(n == 0) return 0;
    else return n + sumN(n-1);
}

// Program 2 (Factorial of N natural Numbers using Recursion)

int factN(int n){
    if (n == 0) return 1;
    else return n * factN(n-1);
}

int main(){
    int N;
    cout << "Enter the number N : ";
    cin >> N;
    cout << "Sum = " << sumN(N) << endl;
    cout << "Factorial = " << factN(N) << endl;
    return 0;
}