class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int i=0,end=0;
        for(vector<int> &v:intervals)
            if(v.back()>end)
                i++,end=v.back();
        return i;
    }
};