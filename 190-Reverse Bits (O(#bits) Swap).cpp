class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        bool a,b;   
        for(int i=0;i<32>>1;i++)
        {
            a=n&1<<i;
            b=n&1<<31-i;
            if(!a&&b||!b&&a)
                n^=1<<i|1<<31-i;
        }
        return n;
    }
};