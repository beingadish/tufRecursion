#include<bits/stdc++.h>
using namespace std;

int a[1000];

// Function 1 (Reverse an Array using iteraion)

void rArray(int a[], int n){
    for(int i =0;i<n/2;i++){
        swap(a[i],a[n-i-1]);
    }
}

// Function 2 (Reverse an Array using Recursion)

void rArrayR(int a[],int l, int r){
    if(l <= r){
        swap(a[l],a[r]);
        rArrayR(a,l+1,r-1);
    }
}

void pArray(int a[],int n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
} // Function for PRINTING ARRAY

void inputArray(int n){
    for(int i=0;i<n;i++) cin >> a[i];
} // For taking input of ARRAY

bool ifPallindrome(string s,int i){  
    int n = s.size();

    
    if(i >= n) return true; // if the pointer crosses the mid value then return TRUE as half of the string is checked and remaining will be same 

    if(s[i] != s[n-i-1]) return false; // if at any point is does not become equal then return false

    return ifPallindrome(s,++i); // if the pointer is behind the mid of the string and also there isn't any case of NOT EQUAL then again check for the next pointer thereby increasing the value of i by one 


} // Function to check whether the String is Pallindrome or Not using Recursion

int main(){
    // int N;
    // cout << "Enter size of Array : ";
    // cin >> N;
    // inputArray(N);
    // cout << "Array Entered : " << endl;
    // pArray(a,N);
    // cout << "Reversing Array using Recursion..."<< endl;
    // rArrayR(a,0,N-1); 
    // cout << "Array after Reverse : ";
    // pArray(a,N);
    string str;
    cout << "Enter STR : ";
    cin >> str;
    cout << ifPallindrome(str,0);
    return 0;
}