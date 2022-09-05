/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<Node*> q;
        q.push(root);
        
        
        
        while(!q.empty())
        {
            int s = q.size();
            vector<int> temp;
            
            for(int i=0; i<s; i++)
            {
                Node* front = q.front();
                q.pop();
                
                temp.push_back(front->val);
                
                for(auto i: (front->children))
                {
                    q.push(i);
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};