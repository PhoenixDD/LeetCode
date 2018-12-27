class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int result=0;
        vector<int> chars_bits(words.size(),0);                         //use bit vector for storing present characters
        for(int i=0;i<words.size();i++)
            for(char &c:words[i])
                chars_bits[i]|=1<<c-'a';
        for(int i=0;i<words.size();i++)
            for(int j=i+1;j<words.size();j++)
                if(!(chars_bits[i]&chars_bits[j]))
                    result=max(result,(int)words[i].length()*(int)words[j].length());
        return result;
    }
};