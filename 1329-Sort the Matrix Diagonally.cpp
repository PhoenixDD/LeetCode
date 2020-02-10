class Solution {
public:
    void Sort(vector<vector<int>>& mat,int i,int j)
    {
        vector<int> result;
        int x=i,y=j,z=0;
        while(i<mat.size()&&j<mat[0].size())
            result.push_back(mat[i++][j++]);
        sort(result.begin(),result.end());
        while(z<result.size())
            mat[x++][y++]=result[z++];
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        for(int j=0;j<mat[0].size();j++)
            Sort(mat,0,j);
        for(int i=1;i<mat.size();i++)
            Sort(mat,i,0);
        return mat;
    }
};