class Solution {
public:
    string fractionToDecimal(long numerator,long denominator)
    {
        string result="";
        if(numerator==0||denominator==0)
            return "0";
        if((numerator<0&&denominator>0)||(numerator>0&&denominator<0))
            result+='-';
        numerator=abs(numerator),denominator=abs(denominator);
        result+=to_string(numerator/denominator);
        numerator%=denominator;
        if(!numerator)
            return result;
        result+='.';
        unordered_map<int,int> map;
        for(long r=numerator;r;r%=denominator)
        {
            if(map.find(r)!=map.end())
            {
                result.insert(map[r],"(");
                result+=')';
                return result;
            }
            map[r]=result.length();
            r*=10;
            result+=to_string(r/denominator);
        }
        return result;
    }
};