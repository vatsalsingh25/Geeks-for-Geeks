//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
    int func(string& str1, string& str2, int ind1, int ind2, vector<vector<int>>&dp){
        
        if(ind1<0 || ind2<0) return 0;                //base case

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(str1[ind1]==str2[ind2]) 
            return dp[ind1][ind2] = 1 + func(str1,str2,ind1-1,ind2-1,dp);           //match condition
        return dp[ind1][ind2] = 0 + max(func(str1,str2,ind1-1,ind2,dp), func(str1,str2,ind1,ind2-1,dp)); //!=match
    }
    // Function to find the length of longest common subsequence in two strings.
    int lcs(string str1, string str2) {
        // your code here
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(str1,str2,n-1,m-1,dp);
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    return str1.size()+str2.size()-2*lcs(str1,str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends