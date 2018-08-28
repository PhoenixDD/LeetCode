class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int rotate=k%nums.size();
        reverse(nums.begin(),nums.begin()+nums.size()-rotate);
        reverse(nums.begin()+nums.size()-rotate,nums.end());
        reverse(nums.begin(),nums.end());
    }
};