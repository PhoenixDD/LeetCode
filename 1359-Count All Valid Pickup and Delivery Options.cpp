//To add 1 pair to already existing n-1 pairs, we have n*2-1 positions for 1 element and n*2 positions for 2nd element, since the pickup is before delivery , it means that the order is determined thus we divide the result by 2. Other way of looking at it is we'll have 2n! permutations and we divide it by 2^n.
static int MOD=1e9+7;
class Solution {
public:
    int countOrders(int n) 
    {
        long result=1;
        for(int i=1;i<=n;i++)
            result=result*(i*2-1)*i%MOD;
        return result;
            
    }
};