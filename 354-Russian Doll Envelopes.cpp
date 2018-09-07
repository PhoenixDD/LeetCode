class Solution {
public:
    int maxEnvelopes(vector<pair<int,int>>& envelopes) 
    {
        if(envelopes.empty())
            return 0;
        auto f=[](pair<int,int> &p1,pair<int,int> &p2)
        {
            if(p1.first==p2.first)
                return p1.second>p2.second;
            return p1.first<p2.first;
        };
        sort(envelopes.begin(),envelopes.end(),f);
        vector<int> heights(envelopes.size());
        for(int i=0;i<envelopes.size();i++)
            heights[i]=envelopes[i].second;
        int len=0,pos;
        for(auto &h:heights)
            if(h>heights[len])
                heights[++len]=h;
            else if(h<heights[len])
                pos=lower_bound(heights.begin(),heights.begin()+len,h)-heights.begin(),heights[pos]=h;
        return len+1;
    }
};