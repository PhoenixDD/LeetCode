class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char,string> map;
        unordered_set<string> mapped;
        map.reserve(pattern.size());
        int found,i,j;
        string temp;
        for(i=0,j=0;i<str.length()&&j<pattern.length();i=found+1,j++)
        {
            found=str.find_first_of(' ',i);
            temp=str.substr(i,found-i);
            if(map.find(pattern[j])==map.end()&&mapped.find(temp)==mapped.end())
                map[pattern[j]]=temp,mapped.insert(temp);
            else if(map[pattern[j]]!=str.substr(i,found-i))
                return false;
        }
        if(j==pattern.length()&&found==string::npos)
            return true;
        return false;
    }
};