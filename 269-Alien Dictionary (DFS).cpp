//Topological sort after making adjList
class Solution {
public:
    string result="";
    vector<char> visited;
    vector<vector<char>> adjList;
    bool topSort(int n)
    {
        visited[n]='G';
        for(char &c:adjList[n])
            if(visited[c-'a']=='G'||visited[c-'a']=='W'&&!topSort(c-'a'))
                return false;
        result+=n+'a';
        visited[n]='B';
        return true;
    }
    string alienOrder(vector<string>& words) 
    {
        visited.resize(26,'X');
        bool diffFlag;
        for(char &c:words.front())
            visited[c-'a']='W';
        adjList.resize(26);
        for(int i=1;i<words.size();i++)
        {
            diffFlag=false;
            for(char &c:words[i])
                visited[c-'a']='W';
            for(int j=0;j<words[i-1].length()&&j<words[i].length();j++)
                if(words[i][j]!=words[i-1][j])    //When the first letter that is unequal is encountered it means prev > curr, we cant decide after that so we break.
                {
                    diffFlag=true;
                    adjList[words[i-1][j]-'a'].push_back(words[i][j]);
                    break;
                }
            if(!diffFlag&&words[i-1].length()>words[i].length())  //We cannot figure out the precedence if ["abc","ab"]
                return "";
                
        }
        for(int i=0;i<26;i++)
            if(visited[i]=='W'&&!topSort(i))
                return "";
        reverse(result.begin(),result.end());
        return result;
    }
};