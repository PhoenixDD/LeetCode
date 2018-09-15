class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<int> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        unordered_map<int,vector<string>> map;
        int temp;
        for(string &s:strs)
        {
            temp=1;
            for(char &c:s)
                temp*=primes[c-'a'];
            map[temp].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it=map.begin();it!=map.end();it++)
            result.push_back(it->second);
        return result;
                
    }
};