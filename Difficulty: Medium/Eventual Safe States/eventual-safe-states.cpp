//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here

        // assume all directions are reversed and then make a adj array
        vector<vector<int>>adjRev(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                adjRev[adj[i][j]].push_back(i);
            }
        }

        vector<int>indegree(V,0);
        //calculate the indegree based on adjRev
        for(int i=0; i<V; i++){
            for(int j=0; j<adjRev[i].size(); j++){
                indegree[adjRev[i][j]]++;
            }
        }

        // push indegree = 0 values to queue
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int>ans;
        // perform the q operation and store values with subsequent 0s in ans array
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends