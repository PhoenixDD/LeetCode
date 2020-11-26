class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) 
    {
        vector<int> cols(picture[0].size(),0);
        int result=0,rowCount=0,col;
        for(int i=0;i<picture.size();i++)
            for(int j=0;j<picture[i].size();j++)
                cols[j]+=picture[i][j]=='B';
        for(int i=0;i<picture.size();i++)
        {
            rowCount=0,col;
            for(int j=0;j<picture[i].size();j++)
                if(picture[i][j]=='B')
                    rowCount++,col=j;
            result+=rowCount==1&&cols[col]==1;
        }
        return result;
    }
};