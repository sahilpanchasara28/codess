//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends

class TrieNode {
    public:
    TrieNode* left;
    TrieNode* right;
    bool isTerminal;
    
    TrieNode() {
       left = NULL;
       right = NULL;
       isTerminal = false;
    }
};
 
class Trie {
    public:
    TrieNode* root;
 
    Trie() {
        root = new TrieNode();
    }
 
    bool insert(vector<int> &word)
    {
        TrieNode* node = root;
        
        for(auto i: word)
        {
            if(i) // 1
            {
                if(node->right == NULL)
                    node->right = new TrieNode();
                
                node = node->right;
            }
            else // 0
            {
                if(node->left == NULL)
                    node->left = new TrieNode();
                
                node = node->left;
            }
        }
        
        if(node->isTerminal)
            return 0;
        
        node->isTerminal = true;
        return 1;
    }
};


vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    Trie* root = new Trie();
    vector<vector<int>> ans;
    
    for(int i=0; i<row; i++)
    {
        vector<int> temp;
        for(int j=0; j<col; j++)
            temp.push_back(M[i][j]);
            
        bool check = root->insert(temp);
        
        if(check)
            ans.push_back(temp);
    }
    
    return ans;
}