class Solution {
public:
    int i=0;
    string decodeString(string &s) 
    {
        string result,temp;
        int times,index;
        while(i<s.length()&&s[i]!=']')
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
                result+=s[i++];
            else
            {
                index=s.find('[',i);
                times=stoi(s.substr(i,index-i));
                i=index+1;
                temp=decodeString(s);
                while(times--)
                    result+=temp;
            }
        i++;
        return result;
    }
};