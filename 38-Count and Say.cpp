class Solution {
public:
    string countAndSay(int n)
    {
        string number="1",number2;
        char num;
        int count;
        while(--n)
        {
            count=1;
            num=number[0];
            number2="";
            for(int i=1;i<number.length();i++)
            {
                if(number[i]==number[i-1])
                    count++;
                else
                {
                    number2+=to_string(count);
                    number2+=num;
                    count=1;
                    num=number[i];
                }
            }
            number2+=to_string(count);
            number2+=num;
            number=number2;
        }
        return number;
    }
};