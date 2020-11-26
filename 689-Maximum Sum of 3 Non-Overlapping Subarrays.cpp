class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        vector<int> kSubSum,result;
        int sum=accumulate(nums.begin(),nums.begin()+k,0),Max=0,left;
        kSubSum.push_back(sum);
        int start=0;
        for(int i=k;i<nums.size();i++)
            sum-=nums[start++],sum+=nums[i],kSubSum.push_back(sum);
        vector<int> right(kSubSum.size());
        right.back()=kSubSum.size()-1;
        left=0;
        for(int i=kSubSum.size()-2;i>=0;i--)
            right[i]=kSubSum[i]>=kSubSum[right[i+1]]?i:right[i+1];
        for(int i=k;i+k<kSubSum.size();i++)
        {
            if(kSubSum[left]+kSubSum[i]+kSubSum[right[i+k]]>Max)
            {
                Max=kSubSum[left]+kSubSum[i]+kSubSum[right[i+k]];
                result={left,i,right[i+k]};
            }
            if(kSubSum[i-k+1]>kSubSum[left])
                left=i-k+1;
        }
        return result;
    }
};