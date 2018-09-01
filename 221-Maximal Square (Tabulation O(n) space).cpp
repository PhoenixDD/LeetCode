class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if(matrix.size()==0)
            return 0;
        int max=0,pre,temp;
        vector<int>memo(matrix.size(),0);
        for(int j=0;j<matrix[0].size();j++)
        {
            pre=memo[0];
            memo[0]=matrix[0][j]=='1'?1:0,max=std::max(memo[0],max);
            for(int i=1;i<matrix.size();i++)
            {
                temp=memo[i];
                if(matrix[i][j]=='1')
                    memo[i]=min(min(memo[i],memo[i-1]),pre)+1,max=std::max(memo[i],max);
                else
                    memo[i]=0;
                pre=temp;
            }
        }
        return max*max;
    }
};