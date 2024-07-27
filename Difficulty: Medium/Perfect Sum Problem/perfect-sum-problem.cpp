//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int func(int arr[], int ind, int sum, vector<vector<int>>&dp){
	    if(sum==0) return 1;
	    if(sum<0) return 0;
	    if(ind==0) return arr[0]==sum;
	    
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    
	    int notPick = func(arr,ind-1,sum,dp);
	    int pick = func(arr,ind-1,sum-arr[ind],dp);
	    
	    return dp[ind][sum]=(pick+notPick)%1000000007;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        sort(arr,arr+n,greater<int>());
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(arr,n-1,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends