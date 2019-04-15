//If n=1 or 2 or 3 , 1st player wins. else if picking 1 or 2 or 3 makes the second player lose, the first player wins
class Solution {
public:
    bool canWinNim(int n) 
    {
        vector<bool> memo(n+1,false);
        memo[1]=memo[2]=memo[3]=true;
        for(int i=4;i<=n;i++)
            memo[i]=!memo[i-1]||!memo[i-2]||!memo[i-3];
        return memo[n];
    }
};