class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int> window(nums.begin(),nums.begin()+k);
        multiset<int>::iterator mid=next(window.begin(),k/2),mid1;
        vector<double> result;
        result.reserve(nums.size()-k+1);
        result.push_back(k&1?*mid:((double)*(--(mid1=mid))+*mid)/2);
        for(int i=k;i<nums.size();i++)
        {
            window.insert(nums[i]);
            if(nums[i]<*mid)
                mid--;
            if(nums[i-k]<=*mid)
                mid++;
            window.erase(window.lower_bound(nums[i-k]));
            result.push_back(k&1?*mid:((double)*(--(mid1=mid))+*mid)/2);
        }
        return result;
    }
};