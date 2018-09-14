class Solution {
public:
    bool validPalindrome(string &s,int i,int j)
    {
        while(i<j&&s[i]==s[j])
            i++,j--;
        return i>=j;
    }
    bool validPalindrome(string s) 
    {
        int i=0,j=s.length()-1;
        while(i<j&&s[i]==s[j])
            i++,j--;
        return i>=j||validPalindrome(s,i+1,j)||validPalindrome(s,i,j-1);
    }
};