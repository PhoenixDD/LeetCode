class Solution {
public:
    string addBinary(string a, string b)
    {
        if(a.empty()&&b.empty())
            return "0";
        bool carry=false;
        int i,j;
        for(i=a.length()-1,j=b.length()-1;i>=0&&j>=0;i--,j--)
        {
            if(i>=j)
            {
                if(a[i]=='0'&&b[j]=='0'&&!carry)
                    a[i]='0';
                else if(a[i]=='0'&&b[j]=='0'&&carry)
                    carry=false,a[i]='1';
                else if(a[i]=='1'&&b[j]=='1'&&!carry)
                    carry=true,a[i]='0';
                else if(a[i]=='1'&&b[j]=='1'&&carry)
                    carry=true,a[i]='1';
                else if(carry&&(a[i]=='1'||b[j]=='1'))
                    a[i]='0';
                else if(!carry&&(a[i]=='1'||b[j]=='1'))
                    a[i]='1';
                    
            }
            else
            {
                if(a[i]=='0'&&b[j]=='0'&&!carry)
                    b[j]='0';
                else if(a[i]=='0'&&b[j]=='0'&&carry)
                    carry=false,b[j]='1';
                else if(a[i]=='1'&&b[j]=='1'&&!carry)
                    carry=true,b[j]='0';
                else if(a[i]=='1'&&b[j]=='1'&&carry)
                    carry=true,b[j]='1';
                else if(carry&&(a[i]=='1'||b[j]=='1'))
                    b[j]='0';
                else if(!carry&&(a[i]=='1'||b[j]=='1'))
                    b[j]='1';
                    
            }
        }
        if(carry)
        {
            if(a.length()>=b.length())
            {
                while(i>=0)
                {
                    if(a[i]=='1')
                        a[i]='0';
                    else
                    {
                        a[i]='1';
                        return a;
                    }
                    i--;
                }
            }
            else
            {
                 while(j>=0)
                {
                    if(b[j]=='1')
                        b[j]='0';
                    else
                    {
                        b[j]='1';
                        return b;
                    }
                    j--;
                }
            }
        }
        else
        {
            if(a.length()>=b.length())
                return a;
            else
                return b;
        }
        if(a.length()>=b.length())
        {
            a.insert(0,"1");
            return a;
        }
        else
        {
            b.insert(0,"1");
            return b;
        }
    }
};