//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int func(vector<int>& arr, int& k, int ind, vector<int>&dp){
        if(ind==0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int mini = INT_MAX;
        for(int i=1; i<=k; i++){
            if(ind>=i){
                int jumpCost=func(arr,k,ind-i,dp)+abs(arr[ind]-arr[ind-i]);
                mini = min(mini,jumpCost);
            } 
        }
        return dp[ind]=mini;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n = arr.size();
        vector<int>dp(n,-1);
        return func(arr,k,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends