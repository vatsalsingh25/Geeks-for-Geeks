//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    void dfs(int node, vector<int>&vis, vector<vector<pair<int,int>>>&adj, stack<int>&st){
        
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it.first]){
                dfs(it.first,vis,adj,st);
            }
        }
        
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        //creating adj array    
        for(int i=0; i<E; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int dist = edges[i][2];
            
            adj[from].push_back({to,dist});    
        }
        
        //applying topo sort(creating stack)
        vector<int>vis(V,0);
        stack<int>st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        //create a distance array
        //empty the elements until the source node is at the top
        vector<int>distance(V,INT_MAX);
        distance[0] = 0; //distancae from source node to source node is 0;
        while(!st.empty()){
            // while(st.top()!=0){     // empty the stack until source(here 0) node is at the top
            //     st.pop();
            // }
            
            int node = st.top();
            st.pop();
            
            if(distance[node] != INT_MAX){
                for(auto it: adj[node]){
                    if(distance[it.first] > distance[node] + it.second){
                        distance[it.first] = distance[node] + it.second;   //{node,dist}  distance of 'node' = distance till here + furthur dist 
                    }    
                }                
            }

        }
        
        //if distance is still INT_MAX, change it to -1;
        for(int i=0; i<V; i++){
            if(distance[i]==INT_MAX) distance[i]=-1;
        }
        
        return distance;
        
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends