//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool func(int ind, int target, int arr[], vector<vector<int>>& dp){
        if(target<0) return false;
        if(target==0) return true;
        if(ind==0) return arr[0]==target;

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notTake = func(ind-1,target,arr,dp);
        bool take = func(ind-1,target-arr[ind],arr,dp);

        return dp[ind][target]=take||notTake;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2==1) return false;

        int target = sum/2;
        vector<vector<int>>dp(N,vector<int>(target+1,-1));
        return func(N-1,target,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends