class Solution {
public:
    bool isValidSerialization(string &preorder,int &i)
    {
        if(i==preorder.length())
            return false;
        int next=preorder.find(',',i);
        string val=preorder.substr(i,next-i);
        i=next==string::npos?preorder.length():next+1;
        if(val=="#")
            return true;
        return isValidSerialization(preorder,i)&&isValidSerialization(preorder,i);
    }
    bool isValidSerialization(string preorder) 
    {
        int i=0;
        return isValidSerialization(preorder,i)&&i==preorder.length();
    }
};