class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int max=0,i=0,j=height.size()-1;
        while(i<j)
        {
            int temp=std::min(height[i],height[j])*(j-i);
            if(temp>max)
                max=temp;
            height[i]>=height[j]?j--:i++;
        }
        return max;
    }
};