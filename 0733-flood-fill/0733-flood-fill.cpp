class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& image, int i, int j,int og, int color)
    {
        if(og == color) return;
        auto valid = [&](int x, int y) {
            return (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == og);
        };
        image[i][j] = color;
        for(auto dir: dirs) {
            if(valid(i+dir[0],j+dir[1]))  {
                dfs(image,i+dir[0],j+dir[1],og,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og = image[sr][sc];
        dfs(image,sr,sc,og,color);
        return image;
    }
};