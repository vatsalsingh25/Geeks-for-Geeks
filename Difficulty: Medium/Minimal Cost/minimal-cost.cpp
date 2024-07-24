//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(vector<int>&height, int k, int ind, vector<int>&dp){
        if(ind==0) return 0;
        
        if(dp[ind]!=0) return dp[ind];
        
        int mini = INT_MAX;
        for(int i=1; i<=k; i++){
            if(ind>=i){
                int jumpCost = f(height,k,ind-i,dp)+abs(height[ind]-height[ind-i]);
                mini = min(mini,jumpCost);
            }
        }
        return dp[ind]=mini;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,0);
        f(height,k,n-1,dp);
        return f(height,k,n-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends