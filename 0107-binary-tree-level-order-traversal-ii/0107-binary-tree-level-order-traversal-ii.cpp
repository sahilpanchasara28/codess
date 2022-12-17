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
    void solve(TreeNode* root, vector<vector<int>> &ans)
    {
        if(root == NULL)
            return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            
            while(n--)
            {
                auto front = q.front();
                q.pop();
                
                temp.push_back(front->val);
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
            }
            
            ans.push_back(temp);
        }
    }
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>> ans;
        
        solve(root, ans);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};