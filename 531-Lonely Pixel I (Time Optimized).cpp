class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) 
    {
        vector<int> rows(picture.size(),0),cols(picture[0].size());
        int result=0;
        for(int i=0;i<picture.size();i++)
            for(int j=0;j<picture[i].size();j++)
                if(picture[i][j]=='B')
                    rows[i]++,cols[j]++;
        for(int i=0;i<picture.size();i++)
            if(rows[i]==1)
                for(int j=0;j<picture[i].size();j++)
                    if(picture[i][j]=='B')
                    {
                        result+=cols[j]==1;
                        break;
                    }
        return result;
    }
};