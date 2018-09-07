class Solution {
public:
    int Min=INT_MAX;
    unordered_set<string> dict;
    bool isconcat(string &w,int start)
    {
        if(start==w.length())
            return true;
        for(int i=start+Min-1;i<w.length();i++)
            if(i-start!=w.length()-1&&dict.find(w.substr(start,i-start+1))!=dict.end()&&isconcat(w,i+1))
                return true;
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
    {
        if(words.empty())
            return {};
        vector<string> result;
        result.reserve(words.size());
        dict.reserve(words.size());
        for(string &w:words)
        {
            dict.insert(w);
            if(!w.empty()&&w.length()<Min)
                Min=w.length();
        }
        for(string &w:words)
            if(Min*2<=w.length()&&isconcat(w,0))
                result.push_back(w);
        return result;
    }
};