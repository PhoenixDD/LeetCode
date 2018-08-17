class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int max=0;
        unordered_set<string> dict;
        vector<bool> memo(s.size()+1,0);
        dict.reserve(wordDict.size());
        for(string &i:wordDict)
            max=std::max(max,(int)i.length()),dict.insert(i);
        memo[0]=true;
        for(int i=1;i<=s.size();i++)
            for(int j=i-1;j>=std::max(i-max,0);j--)
                if(memo[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    memo[i]=true;
                    break;
                }
        return memo[s.size()];
    }
};