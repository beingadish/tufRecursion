// Printing Subsequences whose sum is K

#include<bits/stdc++.h>
using namespace std;

int a[1000]; // Global Array

void inputArray(int n){
    cout << "Enter array elements : ";
    for(int i=0;i<n;i++) cin >> a[i];
} // For taking input of ARRAY


void sumSequences(int index,int s, int arr[], vector<int> &v, int n, int sum){
    if(index == n){
        if(s == sum){    
            cout << "{ ";
            for(auto i : v) cout << i << " ";
            cout << "}" << endl;
        }
        return;
    } 

    v.push_back(arr[index]);
    s+=arr[index];
    sumSequences(index+1,s,arr,v,n,sum);
    v.pop_back();
    s-=arr[index];
    sumSequences(index+1,s,arr,v,n,sum);

} // Printing Subsequences 


// --> Not Recommmended (Most Common Approach)

// if you want to print only one of the subsequence for which the sum will be equal to tht then we can use the flags for it and update it inside the s == sum conditional if statement so that it should stop after printing the 1st occuring subsequence

// --> Recommended (Unique Approach later helpful for DP)


// Changed code is Below :

bool sumSequencesOne(int index,int s, int arr[], vector<int> &v, int n, int sum){
    if(index == n){
        // condition satisfied
        if(s == sum){
            cout << "{ ";
            for(auto i : v) cout << i << " ";
            cout << "}" << endl;
            return true;
        }
        // condition not satisfied
        else return false;
    }

    v.push_back(arr[index]);
    s+=arr[index];
    if(sumSequencesOne(index+1,s,arr,v,n,sum)) return true;
    v.pop_back();
    s-=arr[index];
    if(sumSequencesOne(index+1,s,arr,v,n,sum)) return true;

} // Printing only one subsequence out of all

// Count Subsequences 

int sumSubsequencesCount(int index, int s, int sum, int arr[], vector<int> &v, int n){

    if(index == n){
        if(s == sum) return 1;
        else return 0;
    }

    s+= arr[index];
    int l = sumSubsequencesCount(index+1,s,sum,arr,v,n);
    s-=arr[index];
    int r = sumSubsequencesCount(index+1,s,sum,arr,v,n);
    return l+r;
}


int main(){
    int n,sum;
    cout << "Enter the size of the Array : ";
    cin >> n;
    inputArray(n);
    cout << "Enter the Sum : ";
    cin >> sum;
    vector<int> lst;
    cout << "Sum Sequences are : " << endl << endl;
    sumSequences(0,0,a,lst,n,sum);
    cout << endl << "Total Count of Sum Sequences are : " << sumSubsequencesCount(0,0,sum,a,lst,n) << endl << endl;

    return 0;
}