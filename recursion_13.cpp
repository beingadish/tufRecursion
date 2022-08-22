#include<bits/stdc++.h>
using namespace std;

// Approach 2 (without using any extra DataStructure or HashArray {thereby decreasing the space complexity})

// SWAPPING TECHNIQUE



void permutations2(int index, vector<int> &arr, vector<vector<int>> &ans){

    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i =index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        permutations2(index+1,arr,ans);
        swap(arr[i],arr[index]);
    }
}

vector<vector<int>> solution(vector<int> &arr){
    vector<vector<int>> ans;
    permutations2(0,arr,ans);
    return ans;
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
    inputArray(n,lst);

    // Printing the Solution 

    cout << "[ ";
    for(auto i : solution(lst)){
        cout << "{ ";
        for(auto x : i){
            cout << x << " ";
        }
        cout << "}";
    }
    cout << " ]" << endl;
    return 0;
}