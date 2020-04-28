class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int seenOnce=0,seenTwice=0;
        for(int &i:nums)
        {
            seenOnce=~seenTwice&(seenOnce^i);
            seenTwice=~seenOnce&(seenTwice^i);
        }
        return seenOnce;
    }
};