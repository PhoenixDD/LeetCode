class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        unordered_map<long long,int> memo;
        memo.reserve(1<<42);
        long d;
        int res=0;
        for(int i=1;i<A.size();i++)
            for(int j=0;j<i;j++)
                if((d=(long)A[i]-A[j])>INT_MIN&&d<INT_MAX)
                {
                    memo[d<<10|i]+=1+memo[d<<10|j];
                    res+=memo[d<<10|j];
                }
        return res;
    }
};