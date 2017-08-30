class Solution {
public:
    string multiply(string num1, string num2)
    {
        if(num1=="0"||num2=="0")
            return "0";
        int i=num2.size()-1,carry1=0,res_i=0,temp1,temp2,carry2=0;
        string result="";
        result.reserve(num1.size()+num2.size());
        while(i>=0)
        {
            for(int j=num1.size()-1;j>=0;j--)
            {
                temp1=((int)num2[i]-'0')*((int)num1[j]-'0')+carry1;
                carry1=temp1/10;
                temp1%=10;
                if(res_i<result.length())
                {
                    temp2=((int)result[res_i]-'0')+temp1+carry2;
                    carry2=temp2/10;
                    temp2%=10;
                    result[res_i]=temp2+'0';
                    res_i++;
                }
                else
                {
                    temp2=temp1+carry2;
                    carry2=temp2/10;
                    temp2%=10;
                    result+=temp2+'0';
                    res_i++;
                }
            }
            if(carry2+carry1!=0)
                result+=(carry1+carry2)+'0';
            res_i=num2.size()-i;
            i--;
            carry1=carry2=0;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};