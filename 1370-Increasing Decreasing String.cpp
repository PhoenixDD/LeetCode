class Solution {
public:
    string sortString(string s) 
    {
        vector<int> count(26,0);
        int counter=0;
        string result;
        for(char &c:s)
            count[c-'a']++,counter++;
        int i=0;
        bool dir=true;
        while(counter)
        {
            if(count[i])
                result+=i+'a',count[i]--,counter--;
            if(dir&&i==count.size()-1)
                dir=false;
            else if(!dir&&i==0)
                dir=true;
            else
                dir?i++:i--;
        }
        return result;
    }
};