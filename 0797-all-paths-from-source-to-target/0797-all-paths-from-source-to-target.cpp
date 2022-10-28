class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        
        queue<vector<int>> q;
        q.push({0});
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            if(front.back() == n-1)
            {
                ans.push_back(front);
                continue;
            }
            
            for(auto i: graph[front.back()])
            {
                front.push_back(i);
                q.push(front);
                front.pop_back();
            }
        }
        
        return ans;
    }
};