class Solution {
public:
    string removeVowels(string S) 
    {
        string result;
        unordered_set<char> vowels={'a','e','i','o','u'};
        result.reserve(S.length());
        for(char &c:S)
            if(!vowels.count(c))
                result.push_back(c);
        return result;
    }
};