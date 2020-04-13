//Topological Kahn's algorithm.
class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
        vector<vector<char>> adjList;
        vector<bool> visited(26,false);
        vector<int> inDegree(26,0);
        bool diffFlag;
        adjList.resize(26);
        for(char &c:words.front())
            visited[c-'a']=true;
        for(int i=1;i<words.size();i++)
        {
            diffFlag=false;
            for(char &c:words[i])
                visited[c-'a']=true;
            for(int j=0;j<words[i-1].length()&&j<words[i].length();j++)
                if(words[i][j]!=words[i-1][j])    //When the first letter that is unequal is encountered it means prev > curr, we cant decide after that so we break.
                {
                    diffFlag=true;
                    adjList[words[i-1][j]-'a'].push_back(words[i][j]);
                    inDegree[words[i][j]-'a']++;
                    break;
                }
            if(!diffFlag&&words[i-1].length()>words[i].length())  //We cannot figure out the precedence if ["abc","ab"]
                return "";
                
        }
        queue<int> q;
        string result;
        int count=0;
        for(int i=0;i<26;i++)
            if(visited[i])
            {
                count++;
                if(!inDegree[i])
                    q.push(i);
            }
        while(!q.empty())
        {
            result+=q.front()+'a';
            for(char &c:adjList[q.front()])
                if(--inDegree[c-'a']==0)
                    q.push(c-'a');
            q.pop();
            count--;
        }
        return !count?result:"";
    }
};