class Solution {
public:
    string check;
    bool ispal(int start,int end)
    {
        while(start<=end)
        {
            if(check[start]!=check[end])
                return false;
            start++;end--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        check.reserve(1000);
        check=s;
        for (int len=check.length();len>0;len--)
        {
            for (int i=0;i<=check.length()-len;i++)
            {
                if(ispal(i,len+i-1))
                    return check.substr(i,len);
            }
        }
    }
};