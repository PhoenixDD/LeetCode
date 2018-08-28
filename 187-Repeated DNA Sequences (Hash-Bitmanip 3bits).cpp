class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<int,int> encountered;
        encountered.reserve(pow(4,10));
        vector<string> result;
        int temp=0;
        for(int i=0;i<s.length();i++)
            if(encountered[temp=temp<<3&0x3FFFFFFF|s[i]&7]++==1)
                result.push_back(s.substr(i-9,10));
        return result;
    }
};