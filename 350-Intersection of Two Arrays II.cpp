class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> nums_1;
        unordered_map<int,int>::iterator it;
        vector<int> result;
        result.reserve(nums1.size());
        for(int &i:nums1)
            nums_1[i]++;
        for(int &i:nums2)
            if((it=nums_1.find(i))!=nums_1.end()&&it->second-->0)
                result.push_back(i);
        return result;
    }
};