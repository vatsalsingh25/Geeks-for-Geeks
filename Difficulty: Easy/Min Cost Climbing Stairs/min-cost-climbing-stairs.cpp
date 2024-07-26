//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int func(vector<int>& cost, int ind, vector<int>&dp){
        if(ind>=cost.size())
        {
            return 0;
        }
        
        if(dp[ind]!=-1) return dp[ind];
        
        int oneStep = func(cost,ind+1,dp)+cost[ind];
        int twoStep = func(cost,ind+2,dp)+cost[ind];
        
        return dp[ind]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        vector<int>dp(N+1,-1);
        int a1= func(cost,0,dp);
        vector<int>dp1(N+1,-1);
        int a2=func(cost,1,dp1);
        return min(a1,a2);
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