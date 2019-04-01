//Simple case when the follow up doesnt apply
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(s.empty())
            return true;
        int index=0,i=0;
        while(true)
        {
            index=t.find(s[i++],index);
            if(i==s.length()&&index!=string::npos)
                return true;
            if(index==string::npos)
                return false;
            index++;
        }
    }
};