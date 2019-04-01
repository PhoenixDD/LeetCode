//We can also take k*k pairs/numbers from both arrays and sort them according to the sums and return 1st k pairs.
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        if(nums1.empty()||nums2.empty())
            return {};
        vector<pair<int,int>> result;
        result.reserve(k);
        if(k>=nums1.size()*nums2.size())
        {
            for(int i=0;i<nums1.size();i++)
                for(int j=0;j<nums2.size();j++)
                    result.push_back({nums1[i],nums2[j]});
            return result;
        }
        multimap<int,pair<int,int>> sums;
        sums.insert({nums1[0]+nums2[0],{0,0}});
        vector<vector<bool>> visited(nums1.size(),vector<bool>(nums2.size(),false));
        visited[0][0]=true;
        pair<int,int> temp;
        while(k--&&!sums.empty())
        {
            temp=sums.begin()->second;
            sums.erase(sums.begin());
            result.push_back({nums1[temp.first],nums2[temp.second]});
            if(temp.second!=nums2.size()-1&&!visited[temp.first][temp.second+1])
                sums.insert({nums1[temp.first]+nums2[temp.second+1],{temp.first,temp.second+1}}),visited[temp.first][temp.second+1]=true;
            if(temp.first!=nums1.size()-1&&!visited[temp.first+1][temp.second])
                sums.insert({nums1[temp.first+1]+nums2[temp.second],{temp.first+1,temp.second}}),visited[temp.first+1][temp.second]=true;
        }
        return result;
    }
};