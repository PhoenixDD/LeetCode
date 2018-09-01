class Solution {
public:
    int calculate(string s) {
        int result=0,cur_res=0,temp;
        char op='+';
        for(int i=s.find_first_not_of(' ');i<s.length();i=s.find_first_not_of(' ',i))
        {
            if(isdigit(s[i]))
            {
                temp=s[i]-'0';
                while(++i<s.length()&&isdigit(s[i]))
                    temp=temp*10+s[i]-'0';
                switch(op)
                {
                    case '-': cur_res-=temp;break;
                    case '+': cur_res+=temp;break;
                    case '*': cur_res*=temp;break;
                    case '/': cur_res/=temp;break;
                }
            }    
            else
            {
                if(s[i]=='-'||s[i]=='+')
                    result+=cur_res,cur_res=0;
                op=s[i++];
            }
        }
        return result+cur_res;
    }
};