class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        int len=0;
        vector<string> Snums(nums.size());
        for(int i=0;i<nums.size();i++)
            Snums[i]=to_string(nums[i]),len+=Snums[i].length();
        sort(Snums.begin(),Snums.end(),[](string &a,string &b){return a+b>b+a;});
        if(Snums[0]=="0")
            return "0";
        string res;
        res.reserve(len);
        for(string &i:Snums)
            res+=i;
        return res;
    }
};