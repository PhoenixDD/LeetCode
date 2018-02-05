class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int start=0,end=s.length()-1;
        while(s[end]==' ')
            start++,end--;
        return find(s.rbegin()+start,s.rend(),' ')-(s.rbegin()+start);
    }
};