class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) 
    {
        int prev=-1,result=INT_MAX;
        for(int i=0;i<words.size();i++)
            if(words[i]==word1||words[i]==word2)
            {
                if(prev!=-1&&words[i]!=words[prev])
                    result=min(result,i-prev);
                prev=i;
            }
        return result;
    }
};