static string choice="10";
class Solution {
public:
    string encode(int num) 
    {
        return num>0?encode((num-1)/2)+choice[num&1]:"";
    }
};