class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int second_largest=INT_MAX,third_largest=INT_MAX;
        for(int &n:nums)
            if(n<=third_largest)                                //holds the smallest number.
                third_largest=n;
            else if(n<=second_largest)                          //holds the second smallest number.
                second_largest=n;
            else
                return true;                                    //if there is a number bigger than both of these numbers.
        return false;
    }
};