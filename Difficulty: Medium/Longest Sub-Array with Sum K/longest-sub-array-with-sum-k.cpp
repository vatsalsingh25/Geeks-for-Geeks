//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int cumSum=0;
        int len=0; 
        unordered_map<int,int>mp;
        for(int i=0; i<N; i++){
            cumSum+=A[i];
            if(cumSum==K) len=max(len,i+1);
            int rem=cumSum-K;
            if(mp.find(rem)!=mp.end()) len=max(len,i-mp[rem]) ;
            if(mp.find(cumSum)==mp.end()) mp[cumSum]=i;
        }
        return len;
        
            // if(preSumMap.find(total)==preSumMap.end()){
            //     preSumMap[total]=i;    
            // }

    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends