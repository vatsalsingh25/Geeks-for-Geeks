//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool func(vector<vector<int>>& dp, vector<int>& arr, int ind, int sum){
        if(sum==0) return true;
        if(ind==0) return arr[0]==sum;
        
        if(dp[ind][sum]!=-1) return dp[ind][sum]; // 1
        
        bool notTake = func(dp, arr, ind-1, sum);
        bool take = false;
        if(sum>=arr[ind]){
            take=func(dp, arr,ind-1,sum-arr[ind]);
        }
        
        return dp[ind][sum] = (notTake || take); //2
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(dp, arr,n-1,sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends