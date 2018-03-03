class Solution {
public:
    vector<string> result;
    string temp="";
    bool valid(string &s,int start, int end)
    {
        if(end-start+1==3)
        {
            if(s[start]>'2'||s[start]=='0')
                return false;
            else if(s[start]=='2'&&s[start+1]>'5')
                return false;
            else if(s[start]=='2'&&s[start+1]=='5'&&s[start+2]>'5')
                return false;          
        }
        else if(end-start+1==2&&s[start]=='0')
            return false;
        return true;
    }
    void recur(string s,int start,int octet)
    {
        if(octet==4&&start==s.length())
        {
            temp.pop_back();
            result.push_back(temp);
            temp+='.';
            return;
        }
        else if(octet==4)
            return;
        if(valid(s,start,start))
        {
            temp+=s[start];temp+='.';
            recur(s,start+1,octet+1);
            temp.erase(temp.end()-2,temp.end());
        }
        if(start+1<s.length()&&valid(s,start,start+1))
        {
            temp+=s[start];temp+=s[start+1];temp+='.';
            recur(s,start+2,octet+1);
            temp.erase(temp.end()-3,temp.end());
        }
        if(start+2<s.length()&&valid(s,start,start+2))
        {
            temp+=s[start];temp+=s[start+1];temp+=s[start+2];temp+='.';
            recur(s,start+3,octet+1);
            temp.erase(temp.end()-4,temp.end());
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        temp.reserve(12);
        result.reserve(100);
        recur(s,0,0);
        return result;
    }
};