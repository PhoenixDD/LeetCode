class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int,vector<string>> memo;
    int Max=0;
    vector<string> wordBreak(string &s,int start)
    {
        if(start==s.length())
            return {""};
        if(memo.count(start))
            return memo[start];
        vector<string> result;
        string temp;
        for(int i=start;i<s.length()&&i<start+Max;i++)
        {
            temp=s.substr(start,i-start+1);
            if(dict.count(temp))
            {
                vector<string> next=wordBreak(s,i+1);
                for(string &x:next)
                    result.push_back(temp+(x==""?"":" ")+x);
            }
        }
        return memo[start]=result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        memo.reserve(s.length());
        for(string &s:wordDict)
            Max=max(Max,(int)s.length()),dict.insert(s);
        return wordBreak(s,0);
    }
};