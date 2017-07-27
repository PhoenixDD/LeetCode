class Solution {
public:
    string sum(vector<string> &s,int i)
    {
        if(i==s.size())
            return "";
        return s[i]+sum(s,i+1);
    }
    string convert(string s, int numRows)
    {
        if(s=="")
            return s;
        else if(numRows==1)
            return s;
        bool direction=true;
        vector<string> vec;
        vec.resize(numRows);
        int row=0;
        for(int i=0;i<s.length();i++)
        {   
            vec[row].push_back(s[i]);
            if(row==numRows-1)
                direction=false;
            else if(row==0)
                direction=true;
            direction?row++:row--;
        }
        return sum(vec,0);
    }
};