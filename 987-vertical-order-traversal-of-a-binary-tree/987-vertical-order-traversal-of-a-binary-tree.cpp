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
    void traversal(int i, int j, TreeNode* root, map<int, map<int, multiset<int>>> &m)
    {
        if(root == NULL)
            return;
        
        m[j][i].insert(root->val);
        
        traversal(i+1, j-1, root->left, m);
        traversal(i+1, j+1, root->right, m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        
        traversal(0, 0, root, m);
        
        vector<vector<int>> ans;
        
        for (auto column : m) {
            vector<int> col;
           
            for (auto rows : column.second)
                col.insert(col.end(), rows.second.begin(), rows.second.end());
            
            ans.push_back(col);
        }
        
        return ans;
    }
};