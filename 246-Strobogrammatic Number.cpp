static vector<char> one80={'0','1','x','x','x','x','9','x','8','6'};
class Solution {
public:
    bool isStrobogrammatic(string num)
    {
        for(int i=0;i<num.length();i++)
            if(one80[num[i]-'0']=='x'||one80[num[i]-'0']!=num[num.size()-i-1])
                return false;
        return true;
    }
};