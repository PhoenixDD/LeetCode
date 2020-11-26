static string rotations="01xxxx9x86";
class Solution {
public:
    bool confusingNumber(int N) 
    {
        string nStr=to_string(N);
        for(char &c:nStr)
            if(rotations[c-'0']=='x')
                return false;
            else
                c=rotations[c-'0'];
        reverse(nStr.begin(),nStr.end());
        return nStr!=to_string(N);
    }
};