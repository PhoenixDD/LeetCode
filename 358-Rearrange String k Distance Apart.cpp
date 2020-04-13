class Solution {
public:
    string rearrangeString(string s, int k) 
    {
        if(!k)
            return s;
        string result;
        vector<int> count(26,0);
        int maxCount=0;
        for(char &c:s)
            maxCount=max(maxCount,++count[c-'a']);
        vector<pair<int,char>> sorted;
        for(int i=0;i<count.size();i++)
            if(count[i])
                sorted.push_back({count[i],i+'a'});
        int j;
        while(!sorted.empty())
        {
            if(sorted.size()<k&&maxCount!=1)
                return "";
            sort(sorted.begin(),sorted.end(),greater<pair<int,char>>());
            maxCount=1;
            for(int i=0;i<k&&i<sorted.size();i++)
            {
                result.push_back(sorted[i].second);
                maxCount=max(maxCount,--sorted[i].first);
            }
            j=sorted.size()-1;
            for(int i=0;i<=j;)
                if(!sorted[i].first)
                    swap(sorted[i],sorted[j--]);
                else
                    i++;
            sorted.resize(j+1);
        }
        return result;
    }
};