// Square root decomposition

class NumArray {
public:
    NumArray(vector<int> nums) 
    {
        nums_dup=nums;
        partition_size=sqrt(nums.size());
        if(partition_size==0)
            return;
        decomposed_sums.resize((ceil((double)nums.size()/partition_size)),0);
        for(int i=0;i<nums.size();i++)
            decomposed_sums[i/partition_size]+=nums[i];
    }
    
    void update(int i, int val) 
    {
        decomposed_sums[i/partition_size]+=val-nums_dup[i];
        nums_dup[i]=val;
    }
    
    int sumRange(int i, int j) 
    {
        int sum=0;
        for(int x=i/partition_size;x<=j/partition_size;x++)
            sum+=decomposed_sums[x];
        for(int x=i/partition_size*partition_size;x<i;x++)
            sum-=nums_dup[x];
        for(int x=min(j/partition_size*partition_size+partition_size-1,(int)nums_dup.size()-1);x>j;x--)
            sum-=nums_dup[x];
        return sum;
    }
    private:
    vector<int> decomposed_sums,nums_dup;
    int partition_size;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */