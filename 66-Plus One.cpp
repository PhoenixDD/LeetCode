class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        bool carry=false;
        digits[digits.size()-1]++;
        if(digits[digits.size()-1]<10)
            return digits;
        else
            digits[digits.size()-1]%=10,carry=true;
        for(int i=digits.size()-2;i>=0;i--)
        {
            digits[i]+=carry;
            if(digits[i]<10)
                return digits;
            else
                digits[i]%=10;
        }
        digits.resize(digits.size()+1);
        for(int i=digits.size()-1;i>=0;i--)
            if(i!=0)
                digits[i]=digits[i-1];
            else
                digits[i]=1;
        return digits;
    }
};