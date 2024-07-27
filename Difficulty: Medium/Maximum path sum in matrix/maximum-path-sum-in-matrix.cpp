//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size();
        if(i>=n || j>=n || j<0) return INT_MIN;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j]; //...
        int down = matrix[i][j] + func(i+1,j,matrix,dp);
        int dleft = matrix[i][j] + func(i+1,j-1,matrix,dp);
        int dright = matrix[i][j] + func(i+1,j+1,matrix,dp); 
        return dp[i][j]=max(down,max(dleft,dright)); //...
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int n = Matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1)); //...
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(maxi, func(0,i,Matrix,dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends