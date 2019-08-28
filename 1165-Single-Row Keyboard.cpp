class Solution {
public:
    int calculateTime(string keyboard, string word) 
    {
        vector<int> keyIndices(26,-1);
        for(int i=0;i<keyboard.length();i++)
            keyIndices[keyboard[i]-'a']=i;
        int start=0,result=0;
        for(char &c:word)
            result+=abs(start-keyIndices[c-'a']),start=keyIndices[c-'a'];
        return result;
    }
};