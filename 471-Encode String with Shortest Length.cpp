static unordered_map<string,string> memo;
class Solution {
public:
    int reps(string &s,int start,int end,int l)
    {
        int count=1,i=start+l;
        while(i+l-1<=end)
        {
            if(s.compare(start,l,s,i,l)!=0)
                break;
            count++,i+=l;
        }
        return count;
    }
    string dp(string &s,int start,int end)
    {
        if(end-start+1<5)
            return s.substr(start,end-start+1);
        string sSub=s.substr(start,end-start+1);
        if(memo.count(sSub))
            return memo[sSub];
        string result=s,temp;
        int rep,len;
        for(int i=start;i<=end;i++)
        {
            len=i-start+1;
            rep=reps(s,start,end,len);
            temp=s.substr(start,len)+dp(s,start+len,end);
            if(temp.length()<result.length())
                result=temp;
            for(int r=2;r<=rep;r++) 
            {
                temp=to_string(r)+'['+dp(s,start,start+len-1)+']'+dp(s,start+len*r,end);
                if(temp.length()<result.length())
                    temp.swap(result);
            }
        }
        return memo[sSub]=result;
    }
    string encode(string s)
    {
        return dp(s,0,s.length()-1);
    }
};