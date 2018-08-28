class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int count=0;
        if(n)
            do
            {
                count++;
            }while(n&=n-1);
        return count;
    }
};