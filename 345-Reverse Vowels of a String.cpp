class Solution {
public:
    string reverseVowels(string s) 
    {
        int i=0,j=s.length()-1;
        unordered_set<char> vovels={'a','e','i','o','u'};
        while(i<j)
        {
            if(vovels.count(tolower(s[i]))&&vovels.count(tolower(s[j])))
                swap(s[i],s[j]),i++,j--;
            else if(vovels.count(tolower(s[i])))
                j--;
            else if(vovels.count(tolower(s[j])))
                i++;
            else
                i++,j--;            
        }
        return s;
    }
};