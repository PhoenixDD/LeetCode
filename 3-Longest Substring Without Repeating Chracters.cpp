class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty())
            return 0;
        unordered_map<char,int> lastindex(26);
        long long currentlen=1,max=1,currstartindex=0;
        lastindex[s[0]]=0;
        for(int i=1;i<s.size();i++)
        {
            if(lastindex.find(s[i])==lastindex.end()||lastindex[s[i]]<currstartindex)
            {
                currentlen++;
                if(currentlen>max)
                    max=currentlen;
            }
            else
            {
                currstartindex=lastindex[s[i]]+1;
                currentlen=i-lastindex[s[i]];
            }
            lastindex[s[i]]=i;
        }
        return max;
    }
};