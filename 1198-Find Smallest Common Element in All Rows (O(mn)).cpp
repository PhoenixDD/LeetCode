//O(mn)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) 
    {
        unordered_map<int,int> count;
        unordered_map<int,int>::iterator it;
        for(vector<int> &v:mat)
            for(int &i:v)
                count[i]++;
        int Min=INT_MAX;
        for(it=count.begin();it!=count.end();it++)
            if(it->second==mat.size())
                Min=min(Min,it->first);
        return Min==INT_MAX?-1:Min;
    }
};