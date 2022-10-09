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
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> in;
        inorder(root, in);
        
        int l=0, r=in.size()-1;
        
        while(l < r)
        {
            if(in[l]+in[r] == k)
                return true;
            else if(in[l]+in[r] > k)
                r--;
            else
                l++;
        }
        
        return false;
    }
};