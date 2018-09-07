class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<pair<int,int>> freq(128,pair<int,int>(-1,0));
        for(int i=0;i<s.length();i++)
        {
            if(freq[s[i]].first==-1)
                freq[s[i]].first=i;
            freq[s[i]].second++;
        }
        int result=s.length();
        for(auto &i:freq)
            if(i.second==1)
                result=min(result,i.first);
        return result==s.length()?-1:result;
    }
};