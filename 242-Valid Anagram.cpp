class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.length()!=t.length())
            return false;
        vector<int> count(26);
        for(char &i:s)
            count[i-'a']++;
        for(char &i:t)
        {
            count[i-'a']--;
            if(count[i-'a']<0)
                return false;
        }
        return true;
    }
};