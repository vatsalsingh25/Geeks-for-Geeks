//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&vis,
    vector<pair<int,int>>&temp, int row0, int col0){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || grid[row][col]!=1) return;
        
        vis[row][col]=1;
        temp.push_back({row-row0,col-col0});
        
        dfs(row,col+1,grid,vis,temp,row0,col0);
        dfs(row+1,col,grid,vis,temp,row0,col0);
        dfs(row,col-1,grid,vis,temp,row0,col0);
        dfs(row-1,col,grid,vis,temp,row0,col0);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>temp;
                    dfs(i,j,grid,vis,temp,i,j);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends