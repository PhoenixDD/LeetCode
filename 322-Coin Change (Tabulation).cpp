class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> memo(amount+1,amount+1);
        int Min,temp;
        memo[0]=0;
        for(int v=1;v<=amount;v++)
            for(int i=0;i<coins.size();i++)
                if(coins[i]<=v)
                    memo[v]=min(1+memo[v-coins[i]],memo[v]);
        return memo[amount]==amount+1?-1:memo[amount];
    }
};