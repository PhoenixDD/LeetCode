class Solution {
public:
    int low,high,highDigits;
    vector<int> result;
    void generate(long num,int digits)
    {
        if(num>=low&num<=high)
            result.push_back(num);
        if(digits==highDigits)
            return;
        if(num%10>0)
            generate(num*10+num%10-1,digits+1);
        if(num%10<9)
            generate(num*10+num%10+1,digits+1);
    }
    vector<int> countSteppingNumbers(int low, int high) 
    {
        highDigits=log10(high)+1;
        this->low=low,this->high=high;
        if(!low)
            result.push_back(0);
        for(int i=1;i<=9;i++)
            generate(i,1);
        sort(result.begin(),result.end());
        return result;
    }
};