//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        sort(arr,arr+n);
        for(int i=0; i<=n-3; i++){
            int target = x - arr[i];
            int sum = 0;
            int l = i+1;
            int r = n-1;
            while(l<r){
                sum = arr[l]+arr[r];
                if(sum==target){
                    return true;
                }
                else if(sum>target) r--;
                else l++;                
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends