class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) 
    {
        sort(slots1.begin(),slots1.end(),[](vector<int> &l,vector<int> &r){return l.front()<r.front();});
        sort(slots2.begin(),slots2.end(),[](vector<int> &l,vector<int> &r){return l.front()<r.front();});
        int start,end,i=0,j=0;
        while(i<slots1.size()&&j<slots2.size())
        {
            start=max(slots1[i].front(),slots2[j].front());
            end=min(slots1[i].back(),slots2[j].back());
            if(end-start>=duration)
                return {start,start+duration};
            else if(slots1[i].back()<slots2[j].back())
                i++;
            else
                j++;
        }
        return {};
    }
};