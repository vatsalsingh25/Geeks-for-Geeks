//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        vector<int>distance(100000,INT_MAX);
        queue<pair<int,int>>q;
        
        q.push({start,0});
        distance[start] = 0;
        
        while(!q.empty()){
            int steps = q.front().second;
            int num = q.front().first;
            q.pop();
            
            for(auto it: arr){
                int product = (num*it)%100000;
                if(steps+1<distance[product]){
                    q.push({product,steps+1});
                    distance[product] = steps+1;
                    if(product==end) return steps+1;                    
                }
            }
        }
        return -1;
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends