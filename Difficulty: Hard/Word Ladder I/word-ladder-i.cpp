//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>>q;
        q.push({startWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());

        while(!q.empty()){
            string s = q.front().first;
            int num = q.front().second;
            q.pop();
            if(s==targetWord) return num;
            for(int i=0; i<s.size(); i++){
                for(char ch='a'; ch<='z'; ch++){  
                    string temp = s;  
                    temp[i]=ch;
                    if(st.find(temp)!=st.end()){
                        
                        q.push({temp,num+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends