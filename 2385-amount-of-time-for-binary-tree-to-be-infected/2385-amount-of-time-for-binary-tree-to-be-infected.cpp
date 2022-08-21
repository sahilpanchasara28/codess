/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void buildGraph(TreeNode* root, vector<vector<int>> &adj)
    {
        if(root == NULL)
            return;
        
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        
        buildGraph(root->left, adj);
        buildGraph(root->right, adj);
    }
    
    int bfs(vector<vector<int>> &adj, vector<bool> &vis, int start)
    {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int ans = 0;
        
        while(!q.empty())
        {
            int k = q.size();
            while (k--) {
                int front = q.front();
                q.pop();
                vis[front] = 1;
                
                for(auto i: adj[front])
                    if(!vis[i])
                        q.push(i);
            }    
            ans++;
        }
        return ans-1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        vector<vector<int>> adj(100001);
        
        buildGraph(root, adj);
        
        vector<bool> vis(100001);
        int ans = bfs(adj, vis, start);
        return ans;
    }
};