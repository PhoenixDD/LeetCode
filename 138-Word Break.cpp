class Solution {
public:
    unordered_set<string> dict;
    vector<int> memo;
    int max=0;
    bool wordBreak(string &s,int start)
    {
        if(start==s.length())
            return true;
        if(memo[start]!=-1)
            return memo[start];
        int end=max+start-1;
        for(int i=start;i<s.length()&&i<=end;i++)
            if(dict.find(s.substr(start,i-start+1))!=dict.end()&&wordBreak(s,i+1))
                return memo[start]=true;
        return memo[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        memo.resize(s.length(),-1);
        dict.reserve(wordDict.size());
        for(string &i:wordDict)
            max=std::max(max,(int)i.length()),dict.insert(i);
        return wordBreak(s,0);
    }
};