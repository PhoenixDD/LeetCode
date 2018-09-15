class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<int> memo(n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                    memo[j]=1;
                else if(i==0)
                    memo[j]=memo[j-1];
                else if(j==0)
                    memo[j]=memo[j];
                else
                    memo[j]+=memo[j-1];
            }
        return memo[n-1];
    }
};