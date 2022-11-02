class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_map<string, bool> m;
        unordered_map<string, bool> vis;
        
        for(auto i: bank)
            m[i] = 1;
        
        m[start] = 1;
        string gene = "ACGT";
        queue<pair<string, int>> q;
        q.push({start, 0});
        vis[start] = 1;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            string st = front.first;
            int count = front.second;
            
            if(st == end)
                return count;
            
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(gene[j] != st[i])
                    {
                        char temp = st[i];
                        st[i] = gene[j];
                        
                        if(m[st] and !vis[st])
                        {
                            q.push({st, count+1});
                            vis[st] = 1;
                        }
                        
                        st[i] = temp;
                    }
                }
            }
        }
        return -1;
    }
};