//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// its similar to unbounded knapsak problem
class Solution{
  public:
    int func(int price[], int ind, int length, vector<vector<int>>&dp){
        if(ind==0){
            return price[0]*length/(0+1);                 //(ind+1) is the lenght of the piece of rod
        }
        
        if(dp[ind][length]!=-1) return dp[ind][length];
        
        int notPick = 0+func(price,ind-1,length,dp);
        int pick = INT_MIN;
        if(length>=ind+1) pick = price[ind]+func(price,ind,length-(ind+1),dp);
        
        return dp[ind][length]=max(pick,notPick);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends