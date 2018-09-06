class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        
        int start=0,put,pos;
        vector<int> count(26);
        while(start<s.length()-1)
        {
            fill(count.begin(),count.end(),0);
            for(int i=start;i<s.length();i++)
                count[s[i]-'a']++;
            pos=start;
            for(int i=start;i<s.length();i++)
            {
                if(s[i]<s[pos])
                    pos=i;
                if(--count[s[i]-'a']==0)
                    break;
            }
            put=start;
            s[put++]=s[pos++];
            while(pos<s.length())
            {
                if(s[start]!=s[pos])
                   s[put++]=s[pos];
                pos++;
            }
            s.resize(put);
            start++;
        }
        return s;
    }
};