// Segment tree (Recursive)

class NumArray {
public:
    int build(vector<int> &nums,int index,int l,int r)                                              //Build tree O(n)
    {
        if(l==r)
            return segment_tree[index]=nums[l];
        return segment_tree[index]=build(nums,index*2+1,l,l+r>>1)+build(nums,index*2+2,(l+r>>1)+1,r);
    }
    NumArray(vector<int> nums) 
    {
        if(nums.empty())
            return;
        size=nums.size();
        int height=ceil(log2(size));
        segment_tree.resize((1<<height)*2-1);
        build(nums,0,0,size-1);
    }
    int update(int index,int l,int r,int &i,int &val)                                               //Update value (log(n))
    {
        if(l==r&&r==i)
            return segment_tree[index]=val;
        if(i>=l&&i<=r)
            return segment_tree[index]=update(index*2+1,l,l+r>>1,i,val)+update(index*2+2,(l+r>>1)+1,r,i,val);
        return segment_tree[index];
        
    }
    void update(int i, int val) 
    {
        update(0,0,size-1,i,val);
    }
    int sumRange(int index,int l,int r,int &i,int &j)                                               //Get range sum(log(n))
    {
        if(i<=l&&j>=r)
            return segment_tree[index];
        if(l>j||i>r)
            return 0;
        return sumRange(index*2+1,l,l+r>>1,i,j)+sumRange(index*2+2,(l+r>>1)+1,r,i,j);
    }
    int sumRange(int i, int j) 
    {
        return sumRange(0,0,size-1,i,j);
    }
    private:
    vector<int> segment_tree;
    int size;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */