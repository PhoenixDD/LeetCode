class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
        unordered_map<int,int> sumIndex;
        sumIndex[0]=-1;
        int sum=0,result=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sumIndex.count(sum-k))
                result=max(result,i-sumIndex[sum-k]);
            if(!sumIndex.count(sum))
                sumIndex[sum]=i;
        }
        return result;
    }
};