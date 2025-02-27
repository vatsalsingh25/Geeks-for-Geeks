//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    void dfs(int row, int col, vector<vector<char>>&mat, vector<vector<int>>&vis){
        int m = mat.size();
        int n = mat[0].size();

        if(row<0 || row>=m || col<0 || col>=n || vis[row][col] || mat[row][col]!='O') return; 

        vis[row][col]=1;    

        dfs(row-1,col,mat,vis);   
        dfs(row+1,col,mat,vis); 
        dfs(row,col-1,mat,vis); 
        dfs(row,col+1,mat,vis); 
    }
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        //traverse top and bottom boundry
        for(int j=0; j<n; j++){
            if(mat[0][j]=='O') dfs(0,j,mat,vis);
            if(mat[m-1][j]=='O') dfs(m-1,j,mat,vis);
        }


        //traverse top and bottom boundry
        for(int i=0; i<m; i++){
            if(mat[i][0]=='O') dfs(i,0,mat,vis);
            if(mat[i][n-1]=='O') dfs(i,n-1,mat,vis);
        }


        // visited array is complete after above lines are executed
        // change all the elements to 'X' in board, 
        //except those marked as 1 in vis(ie boundry O and connectd)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==1) continue;
                else mat[i][j]='X'; 
            }
        }

        return mat;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends