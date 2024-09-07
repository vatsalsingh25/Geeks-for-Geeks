//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int func(int val[], int wt[], int W, int ind, vector<vector<int>>&dp){
        if(ind==0){
            return val[0]*(W/wt[0]);
            // if(W>wt[0]) return val[0];
            // return 0;
        }    
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        
        int notPick = 0+func(val,wt,W,ind-1,dp);
        int pick = INT_MIN;
        if(W-wt[ind]>=0) pick = val[ind]+func(val,wt,W-wt[ind],ind,dp);
        
        return dp[ind][W] = max(pick,notPick);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return func(val,wt,W,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends