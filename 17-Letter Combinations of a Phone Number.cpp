class Solution {
public:
    void get_vector(vector<string> &mapping,string &digits,int i,vector<string> &result,string temp)
    {
        if(i==digits.size())
        {
            result.push_back(temp);
            return;
        }
        for(auto j:mapping[(int)digits[i]-'0'])
                get_vector(mapping,digits,i+1,result,temp+j);
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if(digits=="")
            return result;
        vector<string> mapping(10);
        mapping[0]="";mapping[1]="";
        mapping[2]="abc";mapping[3]="def";mapping[4]="ghi";mapping[5]="jkl";
        mapping[6]="mno";mapping[7]="pqrs";mapping[8]="tuv";mapping[9]="wxyz";
        get_vector(mapping,digits,0,result,"");
        return result;
    }
};