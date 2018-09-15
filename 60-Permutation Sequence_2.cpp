class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string result;
        vector<int> fact(10,1);
        set<int> nums;
        set<int>::iterator it;
        for(int i=1;i<=n;i++)
            nums.insert(i);
        for(int i=2;i<10;i++)
            fact[i]=i*fact[i-1];
        it=nums.begin();
        while(1)
        {
            if(k==1)
            {
                result+=*it+'0',nums.erase(it);
                for(int i:nums)
                    result+=i+'0';
                return result;
            }
            else if(k>fact[nums.size()-1])
                k-=fact[nums.size()-1],it++;
            else
                result+=*it+'0',nums.erase(it),it=nums.begin();
        }
        return result;
    }
};