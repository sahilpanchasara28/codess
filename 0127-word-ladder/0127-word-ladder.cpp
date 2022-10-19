class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        int n = targetWord.size();
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        s.erase(startWord);

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            if(front.first == targetWord)
                return front.second;
                
            for(int i=0; i<n; i++)
            {
                string temp = front.first;
                for(char j='a'; j<='z'; j++)
                {
                    temp[i] = j;
                    if(s.find(temp) != s.end())
                    {
                        s.erase(temp);
                        q.push({temp, front.second+1});
                    }
                }
            }
        }
        
        return 0;
    }
};