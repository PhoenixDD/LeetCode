class Solution {
public:
    int n;
    string recur(int num,int level)
    {
        if(level==n)
            return '('+to_string(num)+','+to_string(level-num+1)+')';
        return '('+recur(num,level<<1)+','+recur(level+1-num,level<<1)+')';
    }
    string findContestMatch(int n) 
    {
        this->n=n;
       return recur(1,2);
    }
};