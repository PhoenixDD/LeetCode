class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) 
    {
        unordered_map<string,vector<vector<string>::iterator>> phrasesMap;
        vector<string> result;
        int index,sameCount;
        for(vector<string>::iterator it=phrases.begin();it!=phrases.end();it++)         //Add string to Map by their starting word
                phrasesMap[(*it).substr(0,(*it).find(' '))].push_back(it);     
        for(string &s:phrases)
        {
            sameCount=0;                                                       //Use to track words that are same within the map and s
            for(vector<string>::iterator &it:phrasesMap[s.substr(s.rfind(' ')+1)])
            {
                if(*it==s&&sameCount++!=1)                                      //Only add that word to itself if it occurs more than once.
                    continue;
                index=(*it).find(' ');
                result.push_back(s+(index==-1?"":(*it).substr(index)));
            }
        }
        sort(result.begin(),result.end());                                      //Problem requirement
        result.resize(unique(result.begin(),result.end())-result.begin());      //Problem requirement
        return result;
    }
};