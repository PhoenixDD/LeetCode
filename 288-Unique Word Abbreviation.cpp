class ValidWordAbbr {
public:
    string abv(string &s)
    {
        if(s.length()>2)
            return s.front()+to_string(s.length()-2)+s.back();
        return s;
    }
    ValidWordAbbr(vector<string>& dictionary)
    {
        for(string &s:dictionary)
            if(!dict.count(s))
            {
                dict[s]++;
                if(s.length()>2)
                    dict[abv(s)]++;
            }
    }
    
    bool isUnique(string word) 
    {
        if(!dict.count(abv(word))||dict.count(word)&&dict[abv(word)]==1)
            return true;
        return false;
    }
    unordered_map<string,int> dict;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */