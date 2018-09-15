class Solution {
public:
    int trap(vector<int>& height)
    {
        int left=0,right=0,i=0,j=height.size()-1,result=0;
        while(i<=j)
        {
            if(height[i]<=height[j])
            {
                if(height[i]>left)
                    left=height[i];
                else
                    result+=left-height[i];
                i++;
            }
            else
            {
                if(height[j]>right)
                    right=height[j];
                else
                    result+=right-height[j];
                j--;
            }    
        }
        return result;
    }
};