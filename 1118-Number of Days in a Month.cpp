class Solution {
public:
    int numberOfDays(int Y, int M) 
    {
        return M==2?(Y%4==0&&Y%100!=0||Y%400==0?29:28):M<=7?M&1?31:30:M&1?30:31;
    }
};