//Since 3 is prime, we get the max power of 3 under 32 bits and check if that doesnt leave any remaineder when divided by n
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0&&(int)pow(3,floor(log(INT_MAX)/log(3)))%n==0;
    }
};