//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class TrieNode {
    public:
        TrieNode* children[26];
        bool isTerminal;
    
    TrieNode() {
        for(int i=0; i<26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Solution{
    public:
    TrieNode* root;
    
    Solution() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for(int i=0; i<word.length(); i++)
        {
            char ch = word[i];
            if(node->children[ch-'a'] == NULL)
                node->children[ch-'a'] = new TrieNode();
            
            node = node->children[ch-'a'];
        }
        
        node->isTerminal = true;
     }
 
    bool search(string word) {
        TrieNode* node = root;
        
        for(int i=0; i<word.length(); i++)
        {
            char ch = word[i];
            if(node->children[ch-'a'] == NULL)
                return false;

            node = node->children[ch-'a'];
        }
        
        return node!= NULL && node->isTerminal;
    }
    
    int solve(string A) {
        
        if(A.size() == 0)
            return 1;
        
        for(int i=1; i<=A.size(); i++)
        {
            if(search(A.substr(0, i)) && solve(A.substr(i)))
                return 1;
        }
        
        return 0;
    }
    
    int wordBreak(string A, vector<string> &B) {

    for(auto i: B)
        insert(i);
    
    
    return solve(A);
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends