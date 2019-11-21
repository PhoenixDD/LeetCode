class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string,vector<string>> adjList;
    vector<string> dfs(string &s)
    {
        visited.insert(s);
        vector<string> result,temp;
        result.push_back(s);
        for(string &next:adjList[s])
        {
            if(!visited.count(next))
                temp=dfs(next);
            result.insert(result.end(),temp.begin(),temp.end());
        }
        return result;
    }
    vector<string> result;
    string temp;
    void create(string &s,int i)
    {
        if(i>=s.length())
        {
            temp.pop_back();
            result.push_back(temp);
            temp+=' ';
            return;
        }
        string word=s.substr(i,s.find(' ',i)-i);
        int tmpbegin=temp.length();
        vector<string> tempList;
        if(adjList.count(word))
        {
            visited.clear();
            tempList=dfs(word);
            sort(tempList.begin(),tempList.end());
            for(string &next:tempList)
            {
                temp+=next+' ';
                create(s,i+word.length()+1);
                temp.erase(tmpbegin,temp.length()-tmpbegin);
            }
        }
        else
            temp+=word+' ',create(s,i+word.length()+1),temp.erase(tmpbegin,temp.length()-tmpbegin);
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) 
    {
        for(vector<string> &v:synonyms)
            adjList[v.front()].push_back(v.back()),adjList[v.back()].push_back(v.front());
        create(text,0);
        return result;
    }
};