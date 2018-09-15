class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()||matrix[0].empty())
            return {};
        vector<int> result;
        int l=0,r=matrix[0].size()-1,t=0,b=matrix.size()-1;
        while(l<=r&&t<=b)
        {
            for(int i=l;i<=r;i++)
                result.push_back(matrix[t][i]);
            t++;
            for(int i=t;i<=b;i++)
                result.push_back(matrix[i][r]);
            r--;
            for(int i=r;i>=l&&t<=b;i--)
                result.push_back(matrix[b][i]);
            b--;
            for(int i=b;i>=t&&l<=r;i--)
                result.push_back(matrix[i][l]);
            l++;
        }
        return result;
    }
};