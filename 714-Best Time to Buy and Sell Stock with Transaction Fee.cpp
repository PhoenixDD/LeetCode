class Solution {
public:
    int fee;
    vector<vector<int>> memo;
    long dp(vector<int>& prices, int i,bool buy)
    {
        if(i==prices.size())
            return buy?0:INT_MIN;
        if(memo[i][buy]!=-1)
            return memo[i][buy];
        long result=dp(prices,i+1,buy);
        if(buy)
            result=max(result,-prices[i]+dp(prices,i+1,false));
        else
            result=max(result,prices[i]+dp(prices,i+1,true)-fee);
        return memo[i][buy]=result;
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        this->fee=fee;
        memo.resize(prices.size(),vector<int>(2,-1));
        return dp(prices,0,true);
    }
};