class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if(k<0||t<0||nums.empty())
            return false;
        set<long> m;
        set<long>::iterator it;
        for(int i=0;i<nums.size();i++)
        {
            it=m.lower_bound((long)nums[i]-t);
            if(it!=m.end()&&*it<=(long)nums[i]+t)
                return true;
            m.insert(nums[i]);
            if(m.size()>k)
                m.erase(nums[i-k]);
        }
        return false;
    }
};