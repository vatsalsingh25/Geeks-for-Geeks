//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int func(vector<int>& price, int ind, int check, int limit, vector<vector<vector<int>>>&dp){
            if(limit==0) return 0;
            if(ind==price.size()) return 0;
    
            if(dp[ind][check][limit]!=-1) return dp[ind][check][limit];
    
            int profit = 0;
            if(check==0){
                profit = max(-price[ind]+func(price,ind+1,1,limit,dp), 0+func(price,ind+1,0,limit,dp));
            }
            else{
                profit = max(price[ind]+func(price,ind+1,0,limit-1,dp), 0+func(price,ind+1,1,limit,dp));
            }
            return dp[ind][check][limit]=profit;
        }
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n = price.size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
            return func(price,0,0,2,dp);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends