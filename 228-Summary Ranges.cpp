class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> result;
        int start=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0||i>0&&nums[i-1]+1!=nums[i])
            {
                if(i>0&&nums[i-1]!=start)
                    result.back()+=to_string(nums[i-1]);
                else if(i>0)
                    result.back().pop_back(),result.back().pop_back();
                start=nums[i];
                result.push_back(to_string(nums[i])+"->");
            }
        }
        if(!result.empty()&&nums[nums.size()-1]!=start)
            result.back()+=to_string(nums[nums.size()-1]);
        else if(!result.empty())
            result.back().pop_back(),result.back().pop_back();
        return result;
    }
};