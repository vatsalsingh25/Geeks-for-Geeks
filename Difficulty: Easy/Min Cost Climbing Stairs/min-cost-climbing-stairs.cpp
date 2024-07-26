//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int func(vector<int>& cost, int ind, vector<int>&dp){
        if(ind==0) return 0;
        if(ind==1) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int oneStep = func(cost,ind-1,dp)+cost[ind-1];
        int twoStep = func(cost,ind-2,dp)+cost[ind-2];
        
        return dp[ind]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        vector<int>dp(N+1,-1);
        return func(cost,N,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends