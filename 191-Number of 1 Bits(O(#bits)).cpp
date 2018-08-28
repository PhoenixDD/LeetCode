class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int count=0;
        do
        {
            count+=n&1;
        }while(n>>=1);
        return count;
    }
};