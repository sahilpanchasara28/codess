class Solution {
public:
    void dfs(int i, int j, int n, int m, int color, int originalColor, vector<vector<int>>& image)
    {
        if(i<0 || i>=n || j<0 || j>=m || image[i][j] != originalColor)
            return;
        
        image[i][j] = color;
        
        dfs(i-1, j, n, m, color, originalColor, image);
        dfs(i+1, j, n, m, color, originalColor, image);
        dfs(i, j-1, n, m, color, originalColor, image);
        dfs(i, j+1, n, m, color, originalColor, image);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        if(image[sr][sc] != color)
        dfs(sr, sc, n, m, color, image[sr][sc], image);
        
        return image;
    }
};