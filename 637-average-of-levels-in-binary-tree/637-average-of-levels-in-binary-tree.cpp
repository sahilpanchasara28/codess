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
    vector<double> bfs(TreeNode* root)
    {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int number = q.size();
            double sum = 0;
            
            for(int i=0; i<number; i++)
            {
                auto front = q.front();
                q.pop();
                
                sum += (front->val);
                
                if(front->left)
                    q.push(front->left);
                
                if(front->right)
                    q.push(front->right);
                
            }
            
            ans.push_back(sum/number);
        }
        
        return ans;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        return bfs(root);
    }
};