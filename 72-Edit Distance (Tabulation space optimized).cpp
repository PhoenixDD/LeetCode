class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        vector<int> memo(word1.length()+1);
        int pre,temp;
        for(int i=1;i<=word1.length();i++)
            memo[i]=i;
        for(int j=1;j<=word2.length();j++)
        {
            pre=j-1;	//or memo[0]
            memo[0]=j;
            for(int i=1;i<=word1.length();i++)
            {
                temp=memo[i];
                if(word1[i-1]==word2[j-1])
                    memo[i]=pre;
                else
                    memo[i]=1+min({memo[i-1],pre,memo[i]});
                pre=temp;
            }
        }
        return memo[word1.length()];        
    }
};