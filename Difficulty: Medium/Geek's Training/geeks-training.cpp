//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(vector<vector<int>>& arr, int last, int ind, vector<vector<int>>&dp){
        if(ind==0){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i!=last) maxi = max(maxi,arr[0][i]);
            }
            return maxi;
        } 
        
        if(dp[ind][last]!=-1) return dp[ind][last];
        
        int maxi=0;
        for(int i=0; i<3; i++){
            if(i!=last){
                int points = arr[ind][i]+func(arr,i,ind-1,dp);
                maxi = max(maxi,points);                
            } 
        }
        return dp[ind][last]=maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        // int last = -1;
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return func(arr,3,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends