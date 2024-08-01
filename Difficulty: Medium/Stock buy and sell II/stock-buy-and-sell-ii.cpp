//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
// if 0 can buy if 1 can't buy
    int func(vector<int>& prices, int ind, int check, vector<vector<int>>&dp){
        if(ind==prices.size()) return 0;

        if(dp[ind][check]!=-1) return dp[ind][check];

        int profit = 0;
        if(check==0){
            profit = max( -prices[ind]+func(prices,ind+1,1,dp) , 0+func(prices,ind+1,0,dp));
        }
        else{
            profit = max( prices[ind]+func(prices,ind+1,0,dp), 0+func(prices,ind+1,1,dp));
        }
        return dp[ind][check]=profit;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(prices,0,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends