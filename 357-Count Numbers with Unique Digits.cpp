class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if(!n)
            return 1;
        int unique_count=9,remaining=9,result=10;
        while(--n)
            result+=unique_count*=remaining--;
        return result;
    }
};