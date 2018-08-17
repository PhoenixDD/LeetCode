class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int hold1=INT_MIN,hold2=INT_MIN,sell1=0,sell2=0;
        for(int i=0;i<prices.size();i++)
        {
            hold1=max(hold1,-prices[i]);
            sell1=max(sell1,hold1+prices[i]);
            hold2=max(hold2,sell1-prices[i]);
            sell2=max(sell2,hold2+prices[i]);
        }
        return sell2;
    }
};