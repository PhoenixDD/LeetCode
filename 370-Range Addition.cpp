class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length+1,0);
        for(vector<int> &v:updates)
            result[v[0]]+=v[2],result[v[1]+1]-=v[2];
        int sum=0,curr;
        for(int &i:result)
        {
            curr=i;
            i+=sum;
            sum+=curr;
        }
        result.pop_back();
        return result;
        
    }
};