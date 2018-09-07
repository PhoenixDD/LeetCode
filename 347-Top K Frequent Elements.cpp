class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        vector<vector<int>> buckets(nums.size()+1);
        unordered_map<int,int> map;
        for(int &i:nums)
            map[i]++;
        for(pair<const int,int> &i:map)
            buckets[i.second].push_back(i.first);
        for(int i=nums.size();i>0&&result.size()<k;i--)
            if(!buckets[i].empty())
                result.insert(result.end(),buckets[i].begin(),buckets[i].end());
        result.resize(k);
        return result;
            
    }
};