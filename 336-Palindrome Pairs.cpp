class Solution {
public:
    bool is_pal(string &word,int i,int j)
    {
        while(i<j)
            if(word[i++]!=word[j--])
                return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> result;
        unordered_map<string,int> words_hash;
        unordered_map<string,int>::const_iterator it2;
        string temp;
        for(int i=0;i<words.size();i++)
            words_hash[words[i]]=i;
        for(int i=0;i<words.size();i++)
            for(int j=0;j<=words[i].length();j++)
            {
                if(j>0&&is_pal(words[i],0,j-1))
                {
                    temp=words[i].substr(j);
                    reverse(temp.begin(),temp.end());
                    it2=words_hash.find(temp);
                    if(it2!=words_hash.end()&&it2->second!=i)
                        result.push_back({it2->second,i});
                        
                }
                if(is_pal(words[i],j,words[i].length()-1))
                {
                    temp=words[i].substr(0,j);
                    reverse(temp.begin(),temp.end());
                    it2=words_hash.find(temp);
                    if(it2!=words_hash.end()&&it2->second!=i)
                        result.push_back({i,it2->second});
                }
            }
        return result;
    }
};