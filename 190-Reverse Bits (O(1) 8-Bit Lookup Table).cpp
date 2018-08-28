class Solution {
public:
    #define R2(n) n,n+2*64,n+1*64,n+3*64
    #define R4(n) R2(n),R2(n+2*16),R2(n+1*16),R2(n+3*16)
    #define R6(n) R4(n),R4(n+2*4),R4(n+1*4),R4(n+3*4)
    vector<int> lookup={R6(0),R6(2),R6(1),R6(3)};
    uint32_t reverseBits(uint32_t n)
    {
        int rev=lookup[n&0xff]<<24|lookup[(n>>8)&0xff]<<16|lookup[(n>>16)&0xff]<<8|lookup[(n>>24)&0xff];
        return rev;
    }
};