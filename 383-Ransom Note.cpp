class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> map(26,0);
        for(char &c:magazine)
            map[c-'a']++;
        for(char &c:ransomNote)
            if(!map[c-'a']--)
                return false;
        return true;
    }
};