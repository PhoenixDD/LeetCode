class Solution {
public:
    bool isOneEditDistance(string s, string t) 
    {
        if(abs((int)s.length()-(int)t.length())>=2)
            return false;
        int i=0;
        while(i<s.length()&&i<t.length()&&s[i]==t[i])
            i++;
        if(i==s.length()&&i==t.length())
            return false;
        if(s.length()==t.length())
            return s.compare(i+1,s.length()-i-1,t,i+1,t.length()-i-1)==0;
        if(t.length()>s.length())
            return s.compare(i,s.length()-i,t,i+1,t.length()-i-1)==0;
        return s.compare(i+1,s.length()-i-1,t,i,t.length()-i)==0;
    }
};