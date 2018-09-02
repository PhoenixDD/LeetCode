class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if(nums.empty())
            return {};
        deque<int> dq(k);
        vector<int> result;
        result.reserve(nums.size()-k+1);
        for(int i=0;i<nums.size();i++)
        {
            if(i>k-1)
                result.push_back(nums[dq.front()]);
            while(!dq.empty()&&dq.front()<=i-k)
                dq.pop_front();
            while(!dq.empty()&&nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        return result;
    }
};