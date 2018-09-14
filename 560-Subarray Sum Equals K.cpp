class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> encountered;
        encountered[0]=1;
        int sum=0,result=0;
        for(int &n:nums)
        {
            sum+=n;
            result+=encountered[sum-k];
            encountered[sum]++;
        }
        return result;
    }
};