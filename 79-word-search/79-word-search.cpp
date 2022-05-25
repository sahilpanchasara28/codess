class Solution {
public:
    
    bool solve(vector<vector<char>>& board, string word, int i, int j)
    {
        if(word.empty() || i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[0] != board[i][j])
            return false;
        
        if(word.size() == 1)
            return true;
        
        char temp = board[i][j];
        board[i][j] = '0';
        
        string sub = word.substr(1);
        bool ans = solve(board, sub, i+1, j) || solve(board, sub, i-1, j) ||                   solve(board, sub, i, j+1) || solve(board, sub, i, j-1);
        
        board[i][j] = temp;
        
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(), m = board[0].size();
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j] == word[0] && solve(board, word, i, j))
                    return true;
        
        return false;
    }
};