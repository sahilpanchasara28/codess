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
    
    void dfs(TreeNode* root, int t, vector<int> &temp, vector<vector<int>> &ans)
    {   
        if(root == NULL)
            return;

        temp.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && t == root->val)
            ans.push_back(temp);
        
        dfs(root->left, t-(root->val), temp, ans);
        dfs(root->right, t-(root->val), temp, ans);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, t, temp, ans);
        return ans;
    }
};