class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        int sum=0,result=1;
        for(int &i:nums)
            sum+=i,result=max(result,1-sum);
        return result;
    }
};