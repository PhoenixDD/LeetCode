class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) 
    {
        vector<string> result;
        for(int i=1;i<s.length();i++)
            if(s[i]==s[i-1]&&s[i]=='+')
                s[i]='-',s[i-1]='-',result.push_back(s),s[i]='+',s[i-1]='+';
        return result;
    }
};