class Solution {
public:
    string encode(int num)
    {
        int base=log2(num+1),pow2=(1<<base)-1,i=0;
        string result(base,'0');
        pow2=num-pow2;
        while(pow2)
        {
            if(pow2&1)
                result[i++]='1';
            else
                result[i++]='0';
            pow2>>=1;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};