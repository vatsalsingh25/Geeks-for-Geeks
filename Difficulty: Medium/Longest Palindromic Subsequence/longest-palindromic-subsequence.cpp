//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int func(string s1, string s2, int ind1, int ind2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=1+func(s1,s2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=0+max(func(s1,s2,ind1-1,ind2,dp),func(s1,s2,ind1,ind2-1,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        if (n==0) return 0;
        string s1 = A;
        string s2 = A;
        reverse(s2.begin(),s2.end());   // string s2 = reverse(s.begin(),s.end())  does not work as the reverse function 
                                        //does not return a new string but sort in place

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(s1,s2,n-1,n-1,dp); 
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends