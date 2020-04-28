class Solution {
public:
    bool canPermutePalindrome(string s)
    {
        vector<bool> parity(128,false);
        bool hasTrue=false;
        int count=0;
        for(char &c:s)
            parity[c]=parity[c]^true,count+=parity[c]?1:-1;
        return count<=1;
    }
};