//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        //create adj vector
        vector<vector<pair<int,int>>>adj(n);               //[ [{node,cost},{},{}], [{node,cost},{},{}], .... ]
        for(int i=0; i<flights.size(); i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            adj[from].push_back({to,cost});
        }

        queue<pair<int,pair<int,int>>>q;  //{stops,{node,cost}}
        vector<int>distance(n,INT_MAX);

        q.push({0,{src,0}});
        distance[src] = 0;

        while(!q.empty()){
            int stops = q.front().first; 
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stops>K) continue;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int newCost = it.second + cost;

                if(newCost<distance[adjNode] && stops<=K){
                    distance[adjNode] = newCost;
                    q.push({stops+1,{adjNode,newCost}});
                }
            }
        }

        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends