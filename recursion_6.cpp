#include<bits/stdc++.h>
using namespace std;

int a[1000];

// Print all Subsequences using Recursion

void subsequence(int index, int arr[], vector<int> &lst, int n){
    if(index == n){
        cout << "{ ";
        for(auto it : lst) cout << it << " ";
        cout << "}" << endl;
        return;
    }

    lst.push_back(arr[index]); // take or pick the particular index item into the subsequence list and then call the subsequence recursion call;
    subsequence(index+1,arr,lst,n);
    lst.pop_back(); // not pick or not take the particular index item into the subsequence and then calling the subsequence recursion call;
    subsequence(index+1,arr,lst,n);


    // NOTE : THE ABOVE CALL CAN BE MADE IN REVERSE ORDER ALSO.

    
}

void inputArray(int n){
    for(int i=0;i<n;i++) cin >> a[i];
} // For taking input of ARRAY

int main(){
    int n;
    vector<int> lst;
    cout << "Enter the size of Array : ";
    cin >> n;
    inputArray(n);
    subsequence(0,a,lst,n);
    return 0;
}