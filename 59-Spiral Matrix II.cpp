class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> result(n,vector<int>(n));
        int l=0,r=n-1,t=0,b=n-1,num=1;
        while(l<=r&&t<=b)
        {
            for(int i=l;i<=r;i++)
                result[t][i]=num++;
            t++;
            for(int i=t;i<=b;i++)
                result[i][r]=num++;
            r--;
            for(int i=r;i>=l&&t<=b;i--)
                result[b][i]=num++;
            b--;
            for(int i=b;i>=t&&l<=r;i--)
                result[i][l]=num++;
            l++;
        }
        return result;
    }
};