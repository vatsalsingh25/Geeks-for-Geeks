//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    int func(string& str1, string& str2, int ind1, int ind2, vector<vector<int>>&dp){
        
        if(ind1<0 || ind2<0) return 0;                //base case

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(str1[ind1]==str2[ind2]) 
            return dp[ind1][ind2] = 1 + func(str1,str2,ind1-1,ind2-1,dp);           //match condition
        return dp[ind1][ind2] = 0 + max(func(str1,str2,ind1-1,ind2,dp), func(str1,str2,ind1,ind2-1,dp)); //!=match
    }
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(str1,str2,n-1,m-1,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends