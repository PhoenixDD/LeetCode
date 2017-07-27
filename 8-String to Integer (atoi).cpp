class Solution {
public:
    int myAtoi(string str) 
    {
        if(str.length()==0)
            return 0;
        int i=0,num=0,temp=0;
        bool sign=true;
        while(str[i]==' ')
            i++;
        if(i<str.length()&&str[i]=='-')
        {
            i++;
            sign=false;
        }
        else if(i<str.length()&&str[i]=='+')
            i++;
        if(i<str.length()&&(int)str[i]-'0'>=0&&(int)str[i]-'0'<=9)
        {
            num=(int)str[i]-'0';
            i++;
        }
        else
            return 0;
        if(!sign)
            num=-num;
        while(i<str.length())
        {
            
            if((int)str[i]-'0'>=0&&(int)str[i]-'0'<=9)
            {
                if(!sign)
                {
                    if(num*10-((int)str[i]-'0')>num||num<INT_MIN/10)
                    	return INT_MIN;
                	num=num*10-((int)str[i]-'0');
                }
                else
                {
                    if(num*10+((int)str[i]-'0')<num||num>INT_MAX/10)
                    	return INT_MAX;
                	num=num*10+((int)str[i]-'0');
                }    
            }
            else
                break;
            i++;
        }
        return num;
        
    }
};