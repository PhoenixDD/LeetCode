//https://www.geeksforgeeks.org/orientation-3-ordered-points/
class Solution {
public:
    int getOrientation(vector<vector<int>>& points,int i)
    {
        vector<int> a=points[i],b=points[(i+1)%points.size()],c=points[(i+2)%points.size()];
        return (b.back()-a.back())*(c.front()-b.front())-(c.back()-b.back())*(b.front()-a.front());
        
    }
    bool isConvex(vector<vector<int>>& points) 
    {
        int orientation,decision=0;
        for(int i=0;i<points.size();i++)
        {
            orientation=getOrientation(points,i);
            if(orientation!=0)
            {
                if(decision==0)
                    decision=orientation>0?1:-1;
                else if(decision>0!=orientation>0)
                    return false;
            }
        }
        return true;
    }
};