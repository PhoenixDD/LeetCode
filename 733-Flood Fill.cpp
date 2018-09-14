class Solution {
public:
    vector<int> dirs={-1,0,1,0,-1};
    void dfs(vector<vector<int>>& image,int i,int j,int &c,int &c_old)
    {
        image[i][j]=c;
        for(int x=0;x<4;x++)
            if(i+dirs[x]<image.size()&&j+dirs[x+1]<image[0].size()&&i+dirs[x]>=0&&j+dirs[x+1]>=0&&image[i+dirs[x]][j+dirs[x+1]]==c_old)
                dfs(image,i+dirs[x],j+dirs[x+1],c,c_old);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int c_old=image[sr][sc];
        if(newColor!=c_old)
            dfs(image,sr,sc,newColor,c_old);
        return image;
    }
};