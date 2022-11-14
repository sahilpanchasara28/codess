//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class LinkedList {
    public:
        int index;
        LinkedList* next;
    
    LinkedList(int ind) {
        index = ind;
        next = NULL;
    }
};

class TrieNode {
    public:
        TrieNode* children[26];
        bool isTerminal;
        LinkedList* head;
    
    TrieNode() {
        for(int i=0; i<26; i++)
            children[i] = NULL;
        isTerminal = false;
        head = NULL;
    }
};

class Solution{
  public:
  TrieNode* root;
  
  Solution() {
        root = new TrieNode();
    }
    
    void insert(string word, int ind) {
        TrieNode* node = root;
        
        for(int i=0; i<word.length(); i++)
        {
            char ch = word[i];
            if(node->children[ch-'a'] == NULL)
                node->children[ch-'a'] = new TrieNode();
            
            node = node->children[ch-'a'];
        }
        
        if(node->isTerminal) //word already present
        {
            LinkedList* temp = node->head;
            while(temp->next != NULL)
                temp = temp->next;
                
            temp->next = new LinkedList(ind);
        }
        else
        {
            node->isTerminal = true;
            node->head = new LinkedList(ind);
        }
     }
 
    vector<string> search(string word, vector<string> &st) {
        TrieNode* node = root;
        
        for(int i=0; i<word.length(); i++)
        {
            char ch = word[i];
            node = node->children[ch-'a'];
        }
        
        vector<string> ans;
        
        LinkedList* temp = node->head;
        while(temp != NULL)
        {
            ans.push_back(st[temp->index]);
            temp = temp->next;
        }

        return ans;
    }
  
    vector<vector<string> > Anagrams(vector<string>& st) {
        
        unordered_set<string> list;
        for(int i=0; i<st.size(); i++)
        {
            string stCopy = st[i];
            sort(stCopy.begin(), stCopy.end());
            list.insert(stCopy);
            
            insert(stCopy, i);
        }
        
        vector<vector<string>> ans;
        
        for(auto i: list)
            ans.push_back(search(i, st));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends