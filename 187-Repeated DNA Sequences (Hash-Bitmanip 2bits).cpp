class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> result;
        unordered_map<int,int> encountered;
        encountered.reserve(1048585);
        int bitvec=0;
        for(int i=0;i<s.length();i++)
            if(encountered[bitvec=bitvec<<2&0xFFFFF|(s[i]=='G'?2:s[i]&3)]++==1&&i>=9)
                result.push_back(s.substr(i-9,10));
        return result;
    }
};