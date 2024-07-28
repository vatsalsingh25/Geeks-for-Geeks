//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int func(int wt[], int val[], int ind, int weight, vector<vector<int>>&dp){
        if(ind==0){
            if(weight>=wt[0]) return val[ind];
            else return 0;
        } 
        if(dp[ind][weight]!=-1) return dp[ind][weight];
        //if(weight==0) return 0;
        //if(weight<0) return INT_MIN;    //not correct as the addition to the valueis done and can tbe reversed
        int pick = INT_MIN;
        if(weight>=wt[ind]) pick = val[ind]+func(wt,val,ind-1,weight-wt[ind],dp);
        int notPick = 0+func(wt,val,ind-1,weight,dp);
        
        return dp[ind][weight]=max(pick,notPick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return func(wt,val,n-1,W,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends