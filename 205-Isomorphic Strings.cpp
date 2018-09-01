class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> memo1(128,-1),memo2(128,-1);
        for(int i=0;i<s.length();i++)
        {
            if(memo1[s[i]]==-1&&memo2[t[i]]==-1)
                memo1[s[i]]=memo2[t[i]]=i;
            else if(memo1[s[i]]!=memo2[t[i]])
                return false;
        }
        return true;
    }
};