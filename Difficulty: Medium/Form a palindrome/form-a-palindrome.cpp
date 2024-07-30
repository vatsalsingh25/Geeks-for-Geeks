//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int func(string&s1, string&s2, int ind1, int ind2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2] = 1+func(s1,s2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2] = 0+max(func(s1,s2,ind1-1,ind2,dp),func(s1,s2,ind1,ind2-1,dp));
    }
    
    int findMinInsertions(string S){
        // code here 
        int n = S.size();

        string s1 = S;
        string s2 = S;
        reverse(s2.begin(),s2.end());

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n-func(s1,s2,n-1,n-1,dp);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends