class Solution {
public:
    string convertToTitle(int n) 
    {
        if(!n)
            return "";
        return convertToTitle((n-1)/26)+string(1,(n-1)%26+'A');
    }
};