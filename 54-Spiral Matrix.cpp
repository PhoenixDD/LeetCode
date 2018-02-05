class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if(matrix.empty())
            return {};
        vector<int> result(matrix.size()*matrix[0].size());
        int it=0;
        if(matrix.size()==1||matrix[0].size()==1)
        {
            for(int i=0;i<matrix.size();i++)
                for(int j=0;j<matrix[0].size();j++)
                    result[it++]=matrix[i][j];
            return result;
        }
        int k=0,l=0,m=matrix.size()-1,n=matrix[0].size()-1;
        while(k<=m&&l<=n)
        {
            for(int i=l;i<=n;i++)
                result[it++]=matrix[k][i];
            k++;
            for(int i=k;i<=m;i++)
                result[it++]=matrix[i][n];
            n--;
            for(int i=n;i>=l;i--)
                result[it++]=matrix[m][i];
            m--;
            for(int i=m;i>=k;i--)
                result[it++]=matrix[i][l];
            l++;
        }
        return result;
    }
};