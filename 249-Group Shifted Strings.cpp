int BASE=53,MOD=1e9+7;
class Solution {
public:
    int getGroup(string &s)
    {
        long long result=0;
        int diff=s.front()-'a';
        for(char &c:s)
            result=((result*BASE)%MOD+(((c-'a')-diff)+26)%26)%MOD;
        return ((result*BASE%MOD)+s.length())%MOD;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) 
    {
        unordered_map<int,vector<string>> diff;
        unordered_map<int,vector<string>>::iterator it;
        vector<vector<string>> result;
        for(string &s:strings)
            diff[getGroup(s)].push_back(s);
        for(it=diff.begin();it!=diff.end();it++)
            result.push_back(it->second);
        return result;
    }
};