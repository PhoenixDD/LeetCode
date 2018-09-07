class Solution {
public:
    string frequencySort(string s) 
    {
        string result;
        result.reserve(s.length());
        vector<int> freq(128,0);
        vector<string> bucket(s.length()+1,"");
        for(char &c:s)
            freq[c]++;
        for(int i=0;i<freq.size();i++)
            bucket[freq[i]]+=i;
        for(int i=bucket.size()-1;i>0;i--)
            if(bucket[i]!="")
                for(char &c:bucket[i])
                    result+=string(i,c);
        return result;
    }
};