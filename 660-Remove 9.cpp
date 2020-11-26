//Convert to base-9
class Solution {
public:
    int newInteger(int n) 
    {
        string result;
        while(n)
            result+=n%9+'0',n/=9;
        reverse(result.begin(),result.end());
        return stoi(result);
    }
};