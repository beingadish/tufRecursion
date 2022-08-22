#include<bits/stdc++.h>
using namespace std;

// SUBSET SUM I

// GeeksForGeeks (Subset Sums) Link --> https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// Modified Subsequences Solution to find the summation of all the subsequences hence getting all the SUMS


void subsequence(int index, vector<int> &arr, vector<int> &lst, int n, vector<int> &answer){
    if(index == n){
        int ans=0;

        for(auto it : lst) ans+=it; // Adding all the elements which is stored in the Data Structure used (here lst)

        answer.push_back(ans);
        return;
    }

    lst.push_back(arr[index]);
    subsequence(index+1,arr,lst,n,answer);
    lst.pop_back();
    subsequence(index+1,arr,lst,n,answer);
}

void inputArray(int n, vector<int> &array){

    cout << "Enter array elements : ";
    for(int i=0;i<n;i++) cin >> array[i];

} // For taking input of ARRAY

int main(){

    int n;
    cout << "Enter the size of Array : ";
    cin >> n;
    vector<int> lst(n);
    vector<int> ds,ans;
    inputArray(n,lst);
    subsequence(0,lst,ds,n,ans);
    sort(ans.begin(),ans.end());
    cout << "Sums of all the subsets are : [ ";
    for(auto i : ans) cout << i << " ";
    cout << "]" << endl;
    return 0;
}