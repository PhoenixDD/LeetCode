//keep sorted list of initial pointers to each list Muliset does the job.
//increase index of smallest by 1 add and delete to multiset and check if range is minimum.
//works because lists are sorted.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        multimap<int,pair<vector<vector<int>>::iterator,vector<int>::iterator>> pointers;
        pair<int,pair<vector<vector<int>>::iterator,vector<int>::iterator>> temp;
        for(auto i=nums.begin();i!=nums.end();i++)
            pointers.insert({*i->begin(),{i,i->begin()}});
        int range_begin=INT_MIN,range_end=INT_MAX,Min=INT_MAX,new_range_begin,new_range_end;
        while(1)
        {
            new_range_begin=pointers.begin()->first;
            new_range_end=(--pointers.end())->first;
            if(new_range_end-new_range_begin<Min||new_range_end-new_range_begin==Min&&new_range_begin<range_begin)
                Min=new_range_end-new_range_begin,range_begin=new_range_begin,range_end=new_range_end;
            temp=*pointers.begin();
            pointers.erase(pointers.begin());
            if(++temp.second.second==temp.second.first->end())
                return {range_begin,range_end};
            temp.first=*temp.second.second;
            pointers.insert(temp);
        }
    }
};