class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.size()<2)
            return 0;
        vector<int> right(height.size(),0);
        right.back()=height.back();
        for(int i=height.size()-2;i>=0;i--)
            right[i]=max(height[i],right[i+1]);
        int left=height.front(),water=0;
        for(int i=1;i<height.size()-1;i++)
        {
            left=max(height[i],left);
            water+=min(left,right[i])-height[i];
        }
        return water;
    }
};