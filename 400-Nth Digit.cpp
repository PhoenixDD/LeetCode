class Solution {
public:
    int findNthDigit(int n)
    {
        int l=1;
        long nums_in_l=9;
        while(n-l*nums_in_l>0)                                          //Get the range of where the actual number lies
        {
            n-=l*nums_in_l;
            nums_in_l*=10;
            l++;
        }
        int num_needed=(n-1)/l,exact_digit=(n-1)%l;                    //Get the number and the digit within that number
        long ans=pow(10,l-1)+num_needed;
        while(l-exact_digit-1)              //Reverse iterate that but dividing by 10, the last digit in the remaining number is the result
            ans/=10,exact_digit++;
        return ans%10;
    }
};