class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<string,int> roman2numeric(13);
        roman2numeric["I"]=1;roman2numeric["IV"]=4;roman2numeric["V"]=5;roman2numeric["IX"]=9;roman2numeric["X"]=10;roman2numeric["XL"]=40;
        roman2numeric["L"]=50;roman2numeric["XC"]=90;roman2numeric["C"]=100;roman2numeric["CD"]=400;roman2numeric["D"]=500;
        roman2numeric["CM"]=900;roman2numeric["M"]=1000;
        int numeric=0;string temp;temp.resize(3);
        for(int i=0;i<s.length();i++)
        {
            temp="";
            temp+=s[i];temp+=s[i+1];
            if(roman2numeric.find(temp)==roman2numeric.end())
            {
                numeric+=roman2numeric[string(1,s[i])];
            }
            else
            {
                numeric+=roman2numeric[temp];
                i++;
            }
        }
        return numeric;
    }
};