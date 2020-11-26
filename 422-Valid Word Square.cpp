class Solution {
public:
    bool validWordSquare(vector<string>& words) 
    {
        for(int i=0;i<words.size();i++)
            for(int j=i;j<max(words[i].size(),words.size());j++)
                if(words[i].size()>words.size()||j>=words[i].size()&&words[j].size()>i||j<words[i].size()&&i>=words[j].size()||i<words[j].size()&&j<words[i].size()&&words[i][j]!=words[j][i])
                    return false;
        return true;
    }
};