//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int>visited(leaves+1,0);
        for(int i=0; i<N; i++){
            int jump = frogs[i];
            if(jump<=leaves && !visited[jump]){
                for(int j=0; j<=leaves; j=j+jump){
                    visited[j]=1;
                }                
            }
        }
        
        int count= 0;
        for(int i=1; i<=leaves; i++){
            if(visited[i]==0) count++;
        }
        return count;
        
    }
    //0 1 2 3 4
    //0 0 1 1 1
};
 




//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends