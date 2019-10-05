//Preprocess = O(colors.size) , query = O(log(colors.size))
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) 
    {
        vector<int> result;
        vector<int>::iterator it;
        vector<vector<int>> colorIndices(3);
        for(int i=0;i<colors.size();i++)
            colorIndices[colors[i]-1].push_back(i);
        for(vector<int> &q:queries)
            if(!colorIndices[q[1]-1].empty())
            {
                it=lower_bound(colorIndices[q[1]-1].begin(),colorIndices[q[1]-1].end(),q[0]);   //Binary search on indices
                if(it==colorIndices[q[1]-1].end())
                    result.push_back(abs(q[0]-colorIndices[q[1]-1].back()));
                else if(it==colorIndices[q[1]-1].begin())
                    result.push_back(abs(q[0]-colorIndices[q[1]-1].front()));
                else
                    result.push_back(min(abs(q[0]-*--it),abs(q[0]-*it)));           //Decrement on left as expression evaluated from right
            }
            else
                result.push_back(-1);
        return result;
    }
};