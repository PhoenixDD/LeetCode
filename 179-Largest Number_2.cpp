class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<int> pow10={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
        sort(nums.begin(),nums.end(),[&pow10](int &a,int &b){return (long)a*pow10[b==0?1:(log10(b)+1)]+b>(long)b*pow10[a==0?1:(log10(a)+1)]+a;});
        if(!nums[0])
            return "0";
        string result;
        result.reserve(10000);
        for(int &i:nums)
            result+=to_string(i);
        return result;
    }
};