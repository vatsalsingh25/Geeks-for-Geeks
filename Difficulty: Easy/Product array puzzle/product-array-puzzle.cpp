//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int zero=0;
        vector<long long int>ans(nums.size(),0);
        long long int multi=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zero++;
            else
                multi*=nums[i];
        }
        if(zero>1)
            return ans;
        else if(zero==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                    ans[i]=multi;
            }
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                ans[i]=multi/nums[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends