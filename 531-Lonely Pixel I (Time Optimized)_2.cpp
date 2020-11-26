class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) 
    {
        vector<int> rows(picture.size(),0),cols(picture[0].size());
        vector<pair<int,int>> poss;
        int result=0;
        for(int i=0;i<picture.size();i++)
            for(int j=0;j<picture[i].size();j++)
                if(picture[i][j]=='B')
                    rows[i]++,cols[j]++,poss.push_back({i,j});
        for(pair<int,int> &p:poss)
            result+=rows[p.first]+cols[p.second]==2;
        return result;
    }
};