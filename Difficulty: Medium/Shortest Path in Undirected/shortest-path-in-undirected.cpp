//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int>distances(n,INT_MAX); //stroing he distances
        queue<pair<int,int>>q; //{node,distance}
        
        q.push({src,0});
        distances[src] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(distances[it]==INT_MAX || distances[it]>dist+1){
                    distances[it] = dist+1;
                    q.push({it,dist+1});
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(distances[i]==INT_MAX) distances[i]=-1;
        }
        return distances;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends