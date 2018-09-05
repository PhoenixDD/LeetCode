class Solution {
public:
    string getHint(string secret, string guess)
    {
        int cow=0,bull=0;
        vector<int> map(10);
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                cow++,map[secret[i]-'0']--;
            map[secret[i]-'0']++;
        }
        for(int i=0;i<guess.size();i++)
            if(map[guess[i]-'0']>0&&secret[i]!=guess[i])
                bull++,map[guess[i]-'0']--;
        return to_string(cow)+"A"+to_string(bull)+"B";
    }
};