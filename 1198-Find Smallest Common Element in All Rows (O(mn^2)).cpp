//O(mn) but clear() takes o(n) time so O(mn^2)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) 
    {
        unordered_set<int> exist(mat.front().begin(),mat.front().end()),temp;
        unordered_set<int>::iterator it;
        int Min=INT_MAX;
        for(int i=1;i<mat.size();i++)
        {
            temp.clear();
            for(int &i:mat[i])
                if(exist.count(i))
                    temp.insert(i);
            exist.swap(temp);
        }
        for(it=exist.begin();it!=exist.end();it++)
            Min=min(Min,*it);
        return Min==INT_MAX?-1:Min;
    }
};