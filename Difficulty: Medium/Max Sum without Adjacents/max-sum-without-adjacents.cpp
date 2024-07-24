//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int func(vector<int>& dp, int* arr, int ind){
        if(ind==0) return arr[0];
        if(ind<0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int pick = arr[ind]+func(dp,arr,ind-2);
        int notPick = 0+func(dp,arr,ind-1);
        
        return dp[ind]=max(pick,notPick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return func(dp,arr,n-1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends