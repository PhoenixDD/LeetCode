class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.empty())
            return 0;
        int Min=prices[0],res=0;
        for(int i=1;i<prices.size();i++)
        {
            res=max(res,prices[i]-Min);
            Min=min(Min,prices[i]);
        }
        return res;
    }
};