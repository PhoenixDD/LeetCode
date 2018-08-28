/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#include<functional>
class Solution {
public:
    template <class T>
    static void hash_combine(std::size_t& seed,const T& v)
    {
        seed^=v+0x9e3779b9+(seed<<6)+(seed>>2);
    }
    struct pairhash
    {
        public:
        template <typename X, typename U>
        std::size_t operator()(const std::pair<X, U> &x) const
        {
            size_t hash = 0;
            hash_combine(hash,x.first);
            hash_combine(hash,x.second);
            return hash;
        }
    };
    int maxPoints(vector<Point>& points)
    {
        unordered_map<pair<int,int>,int,pairhash> line;
        line.reserve(points.size()*points.size());
        int max=0,x,y,g,overlap,local;
        for(int i=0;i<points.size();i++)
        {
            local=overlap=0;
            for(int j=i+1;j<points.size();j++)
                if(points[j].x==points[i].x&&points[j].y==points[i].y)
                    overlap++;
                else
                {
                    x=points[j].x-points[i].x,y=points[j].y-points[i].y;
                    g=__gcd(x,y);
                    local=std::max(local,++line[pair<int,int>(x/g,y/g)]);
                }
            max=std::max(max,local+overlap+1);
            line.clear();
        }
        return max;
    }
};