class Solution {
public:
    string intToRoman(int num)
    {
        string result="";
        result.reserve(100);
        int count;
        count=num/1000;
        if(count>0)
        {
            num%=count*1000;
            while(count--)
                result+='M';
        }
        if(num>=900)
            result+="CM",num%=900;
        if(num>=500)
            result+='D',num%=500;
        if(num>=400)
            result+="CD",num%=400;
        count=num/100;
        if(count>0)
        {
            num%=count*100;
            while(count--)
                result+='C';
        }
        if(num>=90)
            result+="XC",num%=90;
        if(num>=50)
            result+='L',num%=50;
        if(num>=40)
            result+="XL",num%=40;
        count=num/10;
        if(count>0)
        {
            num%=count*10;
            while(count--)
                result+='X';
        }
        if(num==9)
            result+="IX",num=0;
        if(num>=5)
            result+='V',num%=5;
        if(num==4)
            result+="IV",num=0;
        while(num--)
            result+='I';
        return result;
    }
};