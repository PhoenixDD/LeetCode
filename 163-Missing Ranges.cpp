class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        if(nums.empty())
        {
            if(lower==upper)
                return {to_string(lower)};
            else
                return {to_string(lower)+"->"+to_string(upper)};
        }
        vector<string> result;
        if(lower<nums.front())
            if((long)nums.front()-lower==1)
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower)+"->"+to_string(min(nums.front()-1,upper)));
        for(int i=1;i<nums.size();i++)
        {
            if((long)nums[i]-nums[i-1]>1)
            {
                if((long)nums[i]-nums[i-1]==2)
                    result.push_back(to_string(nums[i]-1));
                else
                    result.push_back(to_string(nums[i-1]+1)+"->"+to_string(min(nums[i]-1,upper)));
            }
            if(nums[i]>=upper)
                break;
        }
        if(upper>nums.back())
            if((long)upper-nums.back()==1)
                result.push_back(to_string(upper));
            else
                result.push_back(to_string(nums.back()+1)+"->"+to_string(upper));
        return result;
    }
};