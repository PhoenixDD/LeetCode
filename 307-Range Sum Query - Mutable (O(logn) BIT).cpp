// Binary Indexed tree / Fenwick Tree
class NumArray {
public:
    NumArray(vector<int> nums) 
    {
        if(nums.empty())
            return;
        nums_dup=nums;
        BIT.resize(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
            BIT_update(i,nums[i]);
    }
    void BIT_update(int i,int val)
    {
        for(++i;i<BIT.size();i+=i&-i)
            BIT[i]+=val;
    }
    void update(int i, int val) 
    {
        
        BIT_update(i,val-nums_dup[i]);
        nums_dup[i]=val;
    }
    
    int sumRange(int i, int j) 
    {
        int sum=0;
        for(++j;j>0;j&=j-1)
            sum+=BIT[j];
        for(;i>0;i&=i-1)
            sum-=BIT[i];
        return sum;
    }
    private:
    vector<int> BIT,nums_dup;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */