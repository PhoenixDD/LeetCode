class Solution {
public:
    vector<vector<int>> memo;
    int maxProfit(vector<int>& prices,int i,bool hold)                      //Hold stores whether there is a stock already bought
    {
        if(i>=prices.size())
            return 0;
        if(memo[hold][i]!=INT_MIN)
            return memo[hold][i];
        if(hold)                                                            //If holding then try selling and adding the value got
            memo[hold][i]=prices[i]+maxProfit(prices,i+2,false);
        else
            memo[hold][i]=-prices[i]+maxProfit(prices,i+1,true);     //If not holding then try byuing the stock and subtracting spent money
        return memo[hold][i]=max(memo[hold][i],maxProfit(prices,i+1,hold)); //Get Max of previous step and doing nothing (ie no buy or sell)
    }
    int maxProfit(vector<int>& prices) 
    {
        memo.resize(2,vector<int>(prices.size(),INT_MIN));
        return maxProfit(prices,0,false);
    }
};