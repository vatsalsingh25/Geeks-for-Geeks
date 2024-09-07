//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int func(vector<int>&arr, int s1, int ind, vector<vector<int>>&dp){
	    if(ind==0){
	        if(s1==0 && arr[0]==0) return 2;
	        if(s1==0 || arr[0]==s1) return 1;
	        return 0;
	    }
        
        if(dp[ind][s1]!=-1) return dp[ind][s1];
        
        int notPick = func(arr,s1,ind-1,dp);
        int pick = 0;
        if(s1-arr[ind]>=0) pick = func(arr,s1-arr[ind],ind-1,dp);
        
        return dp[ind][s1]=(pick+notPick)%1000000007;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total = 0;
        for(int i=0; i<n; i++){
            total+=arr[i];
        }
        int s1 = (total + d)/2;
        
        if(d>total) return 0;
        if((total+d)%2==1) return 0;
        
        vector<vector<int>>dp(n,vector<int>(s1+1,-1));
        return func(arr,s1,n-1,dp);
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends