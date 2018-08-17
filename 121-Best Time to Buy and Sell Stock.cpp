class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min=INT_MAX,result=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min)
                min=prices[i];
            else
                result=max(result,prices[i]-min);
        }
        return result;
    }
};