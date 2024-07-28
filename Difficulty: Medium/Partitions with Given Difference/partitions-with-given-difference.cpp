//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
	int func(vector<int>&arr, int ind, int sum, vector<vector<int>>&dp){
	    //if(sum==0) return 1;
	    if(ind==0){
	        if(sum==0 && arr[0]==0) return 2;
	        if(sum==0 || arr[0]==sum) return 1;
	        return 0;
	    }
	    if(sum<0) return 0;
	    if(ind==0) return arr[0]==sum;
	    
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    
	    int notPick = func(arr,ind-1,sum,dp);
	    int pick = func(arr,ind-1,sum-arr[ind],dp);
	    
	    return dp[ind][sum]=(pick+notPick)%1000000007;
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        //sort(arr.begin(),arr.end(),greater<int>());
        int total=0;
        for(int i=0; i<n; i++){
            total+=arr[i];
        }
        if(total-d<0) return 0;
        if((total-d)%2==1) return 0;
        
        int sum = (total-d)/2;
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(arr,n-1,sum,dp);
    }
    
    //maths
    //        s1-s2=d
    //        s1=total-s2
    //        total-s2-s2=d
    //        s2=(total-d)/2
    //        we need to find if there exist a subset with sum=s2
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends