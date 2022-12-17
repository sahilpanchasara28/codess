/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void solve(Node* root, vector<vector<Node*>> &ans)
    {
        if(root == NULL)
            return;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<Node*> temp;
            
            while(n--)
            {
                auto front = q.front();
                q.pop();
                
                temp.push_back(front);
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
            }
            
            ans.push_back(temp);
        }
    }
    
    Node* connect(Node* root) {
        vector<vector<Node*>> ans;
        solve(root, ans);
        
        for(auto v: ans)
        {
            for(int i=1; i<v.size(); i++)
            {
                v[i-1]->next = v[i];
            }
        }
        
        return root;
    }
};