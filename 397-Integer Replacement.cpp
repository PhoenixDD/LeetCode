class Solution {
public:
    unordered_map<int,int> memo;
    int integerReplacement(long n) 
    {
        if(n==1)
            return 0;
        if(memo.count(n))
            return memo[n];
        if(n%2==0)
            return memo[n]=1+integerReplacement(n>>1);
        else
            return memo[n]=1+min(integerReplacement(n-1),integerReplacement(n+1));
    }
};