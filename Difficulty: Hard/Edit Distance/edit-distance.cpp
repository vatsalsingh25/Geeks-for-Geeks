//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int func(string&word1, string&word2, int ind1, int ind2, vector<vector<int>>&dp){
        if(ind1<0) return ind2+1;    // insert operation to ind2
        if(ind2<0) return ind1+1;    // delete operations from ind1

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(word1[ind1]==word2[ind2]) return dp[ind1][ind2]=0+func(word1,word2,ind1-1,ind2-1,dp); //no steps required

        int erase = func(word1,word2,ind1-1,ind2,dp);
        int insert = func(word1,word2,ind1,ind2-1,dp);
        int replace = func(word1,word2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=1+min(erase,min(insert,replace));
    }
    
    int editDistance(string s, string t) {
        // Code here
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return func(s,t,n1-1,n2-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends