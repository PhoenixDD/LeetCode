class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>> groups;
        groups.reserve(strs.size());
        vector<int> count;
        string temp;
        temp.reserve(78);
        for(int i=0;i<strs.size();i++)
        {
            temp="";
            count.clear();
            count.resize(26,0);
            for(int j=0;j<strs[i].size();j++)
                count[strs[i][j]-'a']++;
            for(int j=0;j<count.size();j++)
                temp+=to_string(count[j]);
            groups[temp].push_back(strs[i]);
        }
        vector<vector<string>> result(groups.size());
        int j=0;
        for(auto &i:groups)
            result[j++]=i.second;
        return result;
    }
};