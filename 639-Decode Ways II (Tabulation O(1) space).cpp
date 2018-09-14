class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.empty())
            return 0;
        long last,secondlast,next;
        last=1;
        int MOD=1e9+7;
        for(int i=1;i<=s.length();i++)
        {
            if(s[i-1]=='*')
            {
                next=9*last;
                if(i>1&&s[i-2]=='1')
                    next+=9*secondlast;
                else if(i>1&&s[i-2]=='2')
                    next+=6*secondlast;
                else if(i>1&&s[i-2]=='*')
                    next+=15*secondlast;
            }
            else
            {
                next=s[i-1]=='0'?0:last;
                if(i>1&&s[i-2]=='*')
                    next+=s[i-1]<='6'?2*secondlast:secondlast;
                else if(i>1&&(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<='6'))
                    next+=secondlast;
            }
            next%=MOD;
            secondlast=last;
            last=next;
        }
        return next;
    }
};