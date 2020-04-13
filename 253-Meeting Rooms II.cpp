class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        vector<int> starts,ends;
        for(vector<int> &v:intervals)
            starts.push_back(v.front()),ends.push_back(v.back());
        sort(starts.begin(),starts.end()),sort(ends.begin(),ends.end());
        int i=0,j=0,count=0,result=0;
        while(i<starts.size()&&j<ends.size())
        {
            if(starts[i]<ends[j])
                count++,i++;
            else if(starts[i]>ends[j])
                count--,j++;
            else
                i++,j++;
            result=max(result,count);
        }
        return result;
    }
};