class Solution {
public:
    int trap(vector<int>& height) 
    {
        int i=0,j=height.size()-1,sum=0,Max=0,lower;
        while(i<j)
        {
            lower=height[height[i]<height[j]?i++:j--];
            Max=max(Max,lower);
            sum+=Max-lower;
        }
        return sum;
    }
};