class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if(s.length()<10)
            return {};
        unordered_map<string,int> encountered;
        encountered.reserve(10*(s.size()-9));
        vector<string> result;
        string temp;
        for(int i=0;i<s.length()-9;i++)
        {
            temp=s.substr(i,10);
            if(encountered[temp]++==1)
                result.push_back(temp);
        }
        return result;
    }
};