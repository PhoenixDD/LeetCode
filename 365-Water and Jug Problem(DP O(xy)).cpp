class Solution {
public:
    unordered_map<int,bool> memo;
    int X,Y,Z;
    bool dp(int n)
    {
        if(n<0||n>X+Y)
            return false;
        if(n==Z)
            return true;
        if(memo.count(n))
            return memo[n];
        memo[n]=false;
        return memo[n]=dp(n+X)||dp(n-X)||dp(n+Y)||dp(n-Y);
    }
    bool canMeasureWater(int x, int y, int z) 
    {
        if(x==z||y==z)
            return true;
        if(z<0||z>x+y)
            return false;
        X=x,Y=y,Z=z;
        return dp(0);
    }
};