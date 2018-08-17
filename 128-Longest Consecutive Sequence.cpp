class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int,int> map;
        map.reserve(nums.size());
        int result=0;
        for(int &i:nums)
            if(!map[i])
                map[i]=map[i+map[i+1]]=map[i-map[i-1]]=map[i+1]+map[i-1]+1,result=max(map[i],result);
        return result;
    }
};