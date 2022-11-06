class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;

        for(int i=0; i<26; i++)
            children[i] = NULL;

        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word)
    {
        if(word.empty())
        {
            root->isTerminal = true;
            return;
        }
        
        int ind = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[ind] != NULL)
            child = root->children[ind];
        else
        {
            child = new TrieNode(word[0]);
            root->children[ind] = child;
        }
        
        insertUtil(child, word.substr(1));
    }
    
    void insert(string word) {
        insertUtil(root, word);
    }
    
    bool searchUtil(TrieNode* root, string word)
    {
        if(word.empty())
            return root->isTerminal;
        
        int ind = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[ind] != NULL)
            child = root->children[ind];
        else
            return false;
        
        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool startsWithUtil(TrieNode* root, string word)
    {
        if(word.empty())
            return true;
        
        int ind = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[ind] != NULL)
            child = root->children[ind];
        else
            return false;
        
        return startsWithUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */