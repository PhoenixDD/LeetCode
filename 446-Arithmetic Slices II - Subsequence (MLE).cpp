class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        vector<unordered_map<int,int>> memo;
        memo.resize(A.size());
        long d;
        int res=0;
        for(int i=1;i<A.size();i++)
            for(int j=0;j<i;j++)
                if((d=(long)A[i]-A[j])>INT_MIN&&d<INT_MAX)
                {
                    memo[i][d]+=1+memo[j][d];
                    res+=memo[j][d];
                }
        return res;
    }
};