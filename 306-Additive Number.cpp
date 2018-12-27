class Solution {
public:
    bool isAdditiveNumber(string &s,int start,long long last,long long secondlast)
    {
        if(s[start]=='0')
        {
            if(last+secondlast==0)
                return isAdditiveNumber(s,start+1,0,0);
            else
                return false;
        }
        if(start==s.length())
            return true;
        string temp;
        long long number;
        temp.reserve(s.length()-start);
        for(int i=start;i<s.length();i++)
        {
            temp+=s[i];
            number=stoll(temp);
            if(number>LONG_MAX||number>last+secondlast)
                return false;
            if(number==last+secondlast)
                return isAdditiveNumber(s,i+1,secondlast,number);
        }
        return false;
    }
    bool isAdditiveNumber(string num) 
    {
        if(num.length()<3)
            return false;
        long long number1,number2;
        string temp1,temp2;
        temp1.reserve(num.size());
        temp2.reserve(num.size());
        for(int i=0;i<num.length()-2;i++)
        {
            temp2="";
            temp1+=num[i];
            number1=stoll(temp1);
            if(number1>LONG_MAX)
                return false;
            if(num[i+1]!='0')
                for(int j=i+1;j<num.length()-1;j++)
                {
                    temp2+=num[j];
                    number2=stoll(temp2);
                    if(number2>LONG_MAX)
                        break;
                    if(isAdditiveNumber(num,j+1,number1,number2))
                        return true;
                }
            else
                if(isAdditiveNumber(num,i+2,number1,0))
                        return true;
            if(number1==0)
                return false;
        }
        return false;
    }
};