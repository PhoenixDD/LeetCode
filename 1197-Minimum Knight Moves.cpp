//Decompose the problem to just first quadrant due to symmetry.
static const vector<int> directions={2,1,2,-1,-2,1,-2,-1,2};
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
    int minKnightMoves(int x, int y) 
    {
        if(x==0&&y==0)
            return 0;
        x=abs(x),y=abs(y);
        unordered_set<pair<int,int>,pairhash> front,back,visited;
        unordered_set<pair<int,int>,pairhash>::iterator it;
        front.insert({0,0});
        back.insert({x,y});
        visited.insert({0,0});
        visited.insert({x,y});
        int distance=1,a,b;
        while(!front.empty()&&!back.empty())
        {
            unordered_set<pair<int,int>,pairhash> temp;
            if(front.size()>back.size())
                front.swap(back);
            for(it=front.begin();it!=front.end();it++)
                for(int d=0;d<8;d++)
                {
                    a=it->first+directions[d],b=it->second+directions[d+1];
                    if(a>=-4&&b>=-4)			//For cases like 1,1
                    {
                        if(back.count({a,b}))
                            return distance;
                        if(!visited.count({a,b}))
                            visited.insert({a,b}),temp.insert({a,b});
                    }
                }                    
            distance++;
            front.swap(temp);
        }
        return distance;
    }
};