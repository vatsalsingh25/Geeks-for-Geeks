//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long func(vector<long long>& prices, int ind, int check, vector<vector<long long>>&dp){
        if(ind>=prices.size()) return 0;

        if(dp[ind][check]!=-1) return dp[ind][check];

        int profit = 0;
        if(check==0){
            profit = max( -prices[ind]+func(prices,ind+1,1,dp) , 0+func(prices,ind+1,0,dp));
        }
        else{
            profit = max( prices[ind]+func(prices,ind+2,0,dp), 0+func(prices,ind+1,1,dp));
        }
        return dp[ind][check]=profit;
    }
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return func(prices,0,0,dp); 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends