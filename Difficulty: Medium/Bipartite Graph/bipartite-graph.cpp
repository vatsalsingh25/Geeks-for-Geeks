//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>&vis, int color){
        vis[node]=color;  //giving the color to the prev node

        for(auto it: adj[node]){
            if(vis[it]!=-1){
                if(vis[it]==color) return false;
            }
            else{
                //dfs(it,graph,vis,1-color);
                if(dfs(it,adj,vis,1-color)==false) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>vis(n,-1); //visited array, also saves the color
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                //dfs(i,graph,vis,0);
                if(dfs(i,adj,vis,0)==false) return false;
            } 
        }
        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends