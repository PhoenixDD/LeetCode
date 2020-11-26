class Solution {
public:
    vector<string> mapping;
    unordered_set<string> mapped;
    bool bt(string &pat,string &str,int i,int j)
    {
        if(i==pat.length()&&j==str.length())
            return true;
        if(i==pat.length()-1)
            return !mapping[pat[i]-'a'].empty()&&j+mapping[pat[i]-'a'].length()==str.length()&&0==str.compare(j,mapping[pat[i]-'a'].length(),mapping[pat[i]-'a'])||mapping[pat[i]-'a'].empty()&&!mapped.count(str.substr(j));
        if(!mapping[pat[i]-'a'].empty())
        {
            if(j+mapping[pat[i]-'a'].length()>str.length()||str.compare(j,mapping[pat[i]-'a'].length(),mapping[pat[i]-'a']))
                return false;
            return bt(pat,str,i+1,j+mapping[pat[i]-'a'].length());
        }
        for(int s=j;s<=str.length()-pat.length()+i;s++)
        {
            mapping[pat[i]-'a']=str.substr(j,s-j+1);
            if(!mapped.count(mapping[pat[i]-'a']))
            {
                mapped.insert(mapping[pat[i]-'a']);
                if(bt(pat,str,i+1,s+1))
                    return true;
                mapped.erase(mapping[pat[i]-'a']);
            }
            mapping[pat[i]-'a']="";
        }
        return false;
        
    }
    bool wordPatternMatch(string pattern, string str)
    {
        if(pattern.empty()&&str.empty())
            return true;
        if(str.length()<pattern.length()||pattern.empty())
            return false;
        mapping.resize(26,"");
        return bt(pattern,str,0,0);
    }
};