//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        
        int a1 = 0;
        int a2 = 0;
        
        int ans = 0;
        
        while(a1<n && a2<m){
            if(arr1[a1]<=arr2[a2]){
                ans = arr1[a1];
                a1++;
                k--;
            }
            else{
                ans = arr2[a2];
                a2++;
                k--;
            }
            if(k==0) return ans;
        }
        while(a1<n){
            ans=arr1[a1];
            a1++;
            k--;
            if(k==0) return ans;
        }
        while(a2<m){
            ans=arr2[a2];
            a2++;
            k--;
            if(k==0) return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends