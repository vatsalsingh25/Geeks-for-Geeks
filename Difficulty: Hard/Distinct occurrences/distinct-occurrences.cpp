//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod = 1000000007;
    int func(string&s, string&t, int ind1, int ind2,vector<vector<int>>&dp){
        //bases cases cant be written in reverse order cuz it will return 0 before checking if ind2 also reached -1 or not
        if(ind2<0) return 1;   //t matched completly
        if(ind1<0) return 0;   //s iterated compeltly        

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2]%mod;

        if(s[ind1]==t[ind2]) return dp[ind1][ind2] = (func(s,t,ind1-1,ind2-1,dp)%mod+func(s,t,ind1-1,ind2,dp)%mod)%mod;   // (match this one) + (ignore this one)
        return dp[ind1][ind2] = func(s,t,ind1-1,ind2,dp)%mod; // when not a match...reduce the string to find a match;
    }
    
    int subsequenceCount(string s, string t)
    {
      //Your code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(s,t,n-1,m-1,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends