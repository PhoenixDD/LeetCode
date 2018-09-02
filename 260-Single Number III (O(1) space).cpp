class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int x=0;
        for(int &i:nums)
            x^=i;
        x&=~(x-1);
        int a=0,b=0;
        for(int &i:nums)
            x&i?a^=i:b^=i;
        return {a,b};
    }
};