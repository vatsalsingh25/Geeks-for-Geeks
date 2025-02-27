//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&vis){
        int m = grid.size();
        int n = grid[0].size();

        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0 || vis[row][col]) return;

        vis[row][col]=1;

        dfs(row-1,col,grid,vis);  
        dfs(row+1,col,grid,vis);
        dfs(row,col-1,grid,vis);
        dfs(row,col+1,grid,vis);      
    }
public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        //traverse top and bottom boundry
        for(int j=0; j<n; j++){
            if(grid[0][j]==1 && !vis[0][j]) dfs(0,j,grid,vis);
            if(grid[m-1][j]==1 && !vis[m-1][j]) dfs(m-1,j,grid,vis);
        }
        //traverse right and left boundry
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && !vis[i][0]) dfs(i,0,grid,vis);
            if(grid[i][n-1]==1 && !vis[i][n-1]) dfs(i,n-1,grid,vis);
        }

        //count all the 1s in the grid that is not marked in the vis and return the count
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && vis[i][j]==0) count++;
            }
        } 
        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends