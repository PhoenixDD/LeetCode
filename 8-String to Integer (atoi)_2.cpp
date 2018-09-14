class Solution {
public:
    int myAtoi(string str) 
    {
        long result=0;
        int i=-1;
        while(str[++i]==' ');
        bool sign=false;
        if(str[i]=='-')
            i++,sign=true;
        else if(str[i]=='+')
            i++;
        for(;i<str.length();i++)
        {
            if(str[i]>='0'&&str[i]<='9')
                result=result*10+str[i]-'0';
            else
                break;
            if(result>INT_MAX&&!sign)
                return INT_MAX;
            if(result>(long)INT_MAX+1&&sign)
                return INT_MIN;
        }
        return sign?-result:result;
    }
};