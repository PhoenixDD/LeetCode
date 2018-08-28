/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) 
    {
        map<pair<int,int>,int> points_map;
        pair<int,int> point;
        int gcd,l_Max,Max=0,overlap;
        for(int i=0;i<points.size();i++)
        {
            l_Max=0,overlap=0;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[i].x==points[j].x&&points[i].y==points[j].y)
                    overlap++;
                else
                {
                    point=make_pair(points[j].x-points[i].x,points[j].y-points[i].y);
                    gcd=__gcd(point.first,point.second);
                    point.first/=gcd,point.second/=gcd;
                    l_Max=max(l_Max,++points_map[point]);
                }
            }
            points_map.clear();
            Max=max(1+l_Max+overlap,Max);
        }
        return Max;
    }
};