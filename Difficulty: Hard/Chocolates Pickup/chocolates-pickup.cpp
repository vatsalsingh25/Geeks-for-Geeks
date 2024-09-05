//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
        if(i==n-1){
            if(j1==j2) return grid[n-1][j1];
            else{
                return grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxi = -1e9;
        for(int d1=-1; d1<=1; d1++){                        //direction of move in the next row for 1st robot
            for(int d2=-1; d2<=1; d2++){                    //direction of move in the next row for 2st robot
                int value;
                if(j1==j2) value = grid[i][j1]+func(grid,i+1,j1+d1,j2+d2,dp);
                else value = grid[i][j1]+grid[i][j2]+func(grid,i+1,j1+d1,j2+d2,dp);
                
                maxi = max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(grid, 0, 0, m-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends