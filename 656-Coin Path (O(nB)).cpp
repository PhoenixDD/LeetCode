class Solution {
public:
    vector<int> memo,trace;
    int B=0;
    int dp(vector<int> &A,int start)
    {
        if(start==A.size()-1)
            return 0;
        if(memo[start]!=-1)
            return memo[start];
        memo[start]=INT_MAX;
        long temp;
        for(int i=start+1;i<A.size()&&i<=start+B;i++)
            if(A[i]!=-1)
            {
                temp=dp(A,i);
                if(A[i]+temp<memo[start])
                    memo[start]=A[i]+temp,trace[start]=i;
            }
        return memo[start];
    }
    vector<int> cheapestJump(vector<int>& A, int B) 
    {
        if(A.back()==-1||A.front()==-1)
            return {};
        this->B=B;
        vector<int> result;
        memo.resize(A.size(),-1);
        trace.resize(A.size(),-1);
        dp(A,0);
        if(memo[0]==INT_MAX)
            return {};
        int start=0;
        while(start!=-1)
            result.push_back(start+1),start=trace[start];
        return result;
    }
};