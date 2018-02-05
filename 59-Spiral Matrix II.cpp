class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n,vector<int>(n));
        int num=1,k=0,l=0,m=n-1;
        n--;
        while(k<=m&&l<=n)
        {
            for(int i=l;i<=n;i++)
                result[k][i]=num++;
            k++;
            for(int i=k;i<=m;i++)
                result[i][n]=num++;
            n--;
            for(int i=n;i>=l;i--)
                result[m][i]=num++;
            m--;
            for(int i=m;i>=k;i--)
                result[i][l]=num++;
            l++;
        }
        return result;
        
    }
};