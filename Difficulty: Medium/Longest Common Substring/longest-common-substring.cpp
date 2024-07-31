//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int longestCommonSubstr(string s1, string s2) {
	// Write your code here.
    	int n1 = s1.size();
    	int n2 = s2.size();
    
    	vector<vector<int>>dp(n1+1,vector<int>(n2+1));
    
    	for(int i=0; i<=n1; i++){
    		dp[i][0]=0;
    	}
    	for(int j=0; j<=n2; j++){
    		dp[0][j]=0;
    	}
        
        int maxi=0;
    	for(int i=1; i<=n1; i++){
    		for(int j=1; j<=n2; j++){
    			if(s1[i-1]==s2[j-1]){
    			    dp[i][j]= 1 + dp[i-1][j-1];
    			    maxi=max(maxi,dp[i][j]);
    			}       //match condition
    			else dp[i][j] = 0;     //not match         
    		}
    	}
    	
    	return maxi;
    	
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends