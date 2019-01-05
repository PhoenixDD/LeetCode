//Num!=0,num has only single '1'(divisible by 2), num's '1' bit is at even place.
class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        return num&&!(num&num-1)&&num&0x55555555;
    }
};