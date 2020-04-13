static int pow2[26]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432};
class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if(s.length()<k)
            return false;
        int bitVec=0,singles,doubles;
        for(char &c:s)
            bitVec^=pow2[c-'a'];
        singles=__builtin_popcount(bitVec);
        doubles=s.length()-singles;
        return singles<=k;
    }
};