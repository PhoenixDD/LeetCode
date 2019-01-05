class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> nums_1(nums1.begin(),nums1.end());
        vector<int> result;
        result.reserve(nums_1.size());
        for(int &i:nums2)
            if(nums_1.erase(i))							//Returns 1 if success
                result.push_back(i);
        return result;
    }
};