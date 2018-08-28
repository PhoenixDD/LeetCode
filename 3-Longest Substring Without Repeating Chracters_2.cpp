class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        bool flag=false;
        vector<int> map(128,0);
        int i=0,Max=0,begin=0;
        for(int i=0;i<s.length();i++)
        {
            flag=map[s[i]]++==1;
            while(flag)
                flag=!(map[s[begin++]]--==2);
            Max=max(i-begin+1,Max);
        }
        return Max;
    }
};