//We can simply hash the entire row as a string and use that as a column check for 'B'
static int MOD=1e9+7,BASE=3;
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) 
    {
        int result=0,rowCount;
        long hash;
        vector<int> col(picture[0].size(),0),colsWithN;
        unordered_map<int,vector<int>> rowHashesMap;
        for(int i=0;i<picture.size();i++)
        {
            hash=0;
            rowCount=0;
            for(int j=0;j<picture[i].size();j++)
            {
                hash*=BASE;
                if(picture[i][j]=='B')
                {
                    hash+=2;
                    col[j]++;
                    rowCount++;
                }
                else
                    hash++;
                hash%=MOD;
            }
            if(rowCount==N)
                rowHashesMap[hash].push_back(i);
        }
        for(int i=0;i<col.size();i++)           //To only iterate on columns with N 'B's
            if(col[i]==N)
                colsWithN.push_back(i);
        for(auto &p:rowHashesMap)
            if(p.second.size()==N)
                for(int &i:colsWithN)           //Iterate on all columns with N 'B's
                    result+=picture[p.second.front()][i]=='B'?N:0; //if 1 of the rows contain 'B' at the col i, all will contain then at that pos
        return result;
                
    }
};