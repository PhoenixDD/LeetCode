class Solution {
public:
    bool helper(vector<int>& x,int i,int up,int left,int down,int right)
    {
        if(i==x.size())
            return false;
        if(up>=down&&left<=right)
            return true;
        if(i+1<x.size()&&left==right&&down-up<=x[i+1])
            return true;
        if(i+2<x.size()&&x[i+1]>=down-up&&x[i+1]<=down&&right>left&&right-left<=x[i+2])
            return true;
        return helper(x,i+1,left,down,right,x[i+1]);
        
        
    }
    bool isSelfCrossing(vector<int>& x) 
    {
        return x.size()<4?false:helper(x,3,x[0],x[1],x[2],x[3]);
    }
};