class Solution {
public:
    vector<int> memo;
    int num(int x)
    {
        if(x==1||x==0)
            return 1;
        if(memo[x]!=-1)
            return memo[x];
        int sum=0;
        for(int i=1;i<=x;i++)
            sum+=num(i-1)*num(x-i);
        return memo[x]=sum;            
    }
    int numTrees(int n) 
    {
        memo.resize(n+1,-1);
        return num(n);
    }
};