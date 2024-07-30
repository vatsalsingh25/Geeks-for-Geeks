//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool func(string&s, string&p, int ind1, int ind2, vector<vector<int>>&dp){
        if(ind1<0 && ind2<0) return true;
        if(ind2<0 && ind1>=0) return false;
        if(ind1<0 && ind2>=0){
            for(int i=0; i<=ind2; i++){
                if(p[i]!='*') return false;
            }
            return true;
        }

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(p[ind2]==s[ind1] || p[ind2]=='?') return dp[ind1][ind2]=func(s,p,ind1-1,ind2-1,dp);
        if(p[ind2]=='*') return dp[ind1][ind2] = func(s,p,ind1-1,ind2,dp) || func(s,p,ind1,ind2-1,dp);    
        // important...let * be nothing or let * be the current character 
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(s,p,n-1,m-1,dp);
    }
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        return isMatch(str,pattern);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends