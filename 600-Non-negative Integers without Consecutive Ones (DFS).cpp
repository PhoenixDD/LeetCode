class Solution {
public:
    int N,res=1;
    void dfs(int n)
    {
        if(n>N||(n&3)==3)
            return;
        res++;
        dfs(n*2);
        dfs(n*2+1);
    }
    int findIntegers(int num) 
    {
        N=num;
        //int len=ceil(log2(num));
        //return fib(len+2);
        dfs(1);
        return res;
    }
};