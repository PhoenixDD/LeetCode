class Solution {
public:
    void reverseWords(string &s)
    {
        int i=0;
        int last=0,put=0;
        reverse(s.begin(),s.end());
        while(s[i]==' ')
            i++,last++;
        for(;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                if(put!=0)
                    s[put++]=' ';
                reverse(s.begin()+last,s.begin()+i);
                while(last!=i)
                    s[put++]=s[last++];
                while(s[i+1]==' ')
                    i++,last++;
                last++;
                if(last==s.length())
                    s.resize(put);
            }
            else if(i==s.length()-1)
            {
                if(put!=0)
                    s[put++]=' ';
                reverse(s.begin()+last,s.begin()+i+1);
                while(last!=i+1)
                    s[put++]=s[last++];
                s.resize(put);
            }
        }
        i=s.length()-1;
        while(i>=0&&s[i]==' ')
            i--;
        if(i>=0&&i!=s.length()-1)
            s.resize(i);
        else if(i<0)
            s.resize(0);
    }
};