class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int max=0,i=0,j=height.size()-1;
        while(i<j)
        {
            max=std::max(max,std::min(height[i],height[j])*(j-i));
            height[i]>=height[j]?j--:i++;
        }
        return max;
    }
};