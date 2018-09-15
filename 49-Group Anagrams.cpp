class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> map;
        stringstream res;
        vector<int> count(26,0);
        vector<vector<string>> result;
        for(string &s:strs)
        {
            for(char &c:s)
                count[c-'a']++;
            copy(count.begin(),count.end(),ostream_iterator<int>(res));
            map[res.str()].push_back(s);
            fill(count.begin(),count.end(),0);
            res.str("");
        }
        for(unordered_map<string,vector<string>>::iterator it=map.begin();it!=map.end();it++)
            result.push_back(it->second);
        return result;
    }
};