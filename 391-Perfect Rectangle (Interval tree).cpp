class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rec) 
    {
        vector<vector<int>> points;
        int minx=INT_MAX,miny=INT_MAX,maxy=INT_MIN,maxx=INT_MIN,maxx_miny=INT_MAX,maxx_maxy=INT_MIN,minx_miny=INT_MAX,minx_maxy=INT_MIN;
        long long small_area=0;
        for(auto &r:rec)
        {
            points.push_back({r[0],r[1],r[3],true});
            points.push_back({r[2],r[1],r[3],false});
            minx=min(minx,r[0]);
            miny=min(miny,r[1]);
            maxx=max(maxx,r[2]);
            maxy=max(maxy,r[3]);
            small_area+=(r[3]-r[1])*(r[2]-r[0]);
        }
        if(small_area!=(maxy-miny)*(maxx-minx))
            return false;
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){return a[0]==b[0]?a[3]<b[3]:a[0]<b[0];});
        set<pair<int,int>> y;
        set<pair<int,int>>::const_iterator it;
        for(vector<int> &p:points)
        {
            if(p[3])
            {
                it=y.lower_bound({p[1],p[2]});
                if(it!=y.end()&&it->first<p[2]||it!=y.begin()&&(--it)->second>p[1])
                    return false;
                y.insert({p[1],p[2]});
            }
            else
                y.erase({p[1],p[2]});
        }
        return true;
    }
};