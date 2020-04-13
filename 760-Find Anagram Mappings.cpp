class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) 
    {
        vector<int> result;
        unordered_map<int,int> indices;
        for(int i=0;i<B.size();i++)
            indices[B[i]]=i;
        for(int &i:A)
            result.push_back(indices[i]);
        return result;
    }
};