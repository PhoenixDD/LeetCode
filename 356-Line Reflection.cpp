class Solution {
public:
    template <class T>
    static void hash_combine(std::size_t& seed,const T& v)
    {
        seed^=v+0x9e3779b9+(seed<<6)+(seed>>2);
    }
    struct vecHash
    {
        template <typename X>
        size_t operator()(const vector<X> &x)const
        {
            size_t hash = 0;
            for(const X &i:x)
                hash_combine(hash,i);
            return hash;
        }
    };
    unordered_set<vector<int>,vecHash> memo;
    bool isReflected(vector<vector<int>>& points) 
    {
        int Max=INT_MIN,Min=INT_MAX;
        for(vector<int> &p:points)
            Max=max(Max,p.front()),Min=min(Min,p.front()),memo.insert(p);
        for(vector<int> &p:points)
        {
            if(!memo.count({Max+Min-p.front(),p.back()}))
                return false;
        }
        return true;
    }
};