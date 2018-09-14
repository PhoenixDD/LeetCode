class Solution {
public:
    void gen(vector<string> &paras,int left,int right,string result)
    {
        if(left==0&&right==0)
        {
            paras.push_back(result);
            return;
        }
        if(left<0||right<left)
            return;
        gen(paras,left-1,right,result+'(');
        gen(paras,left,right-1,result+')');
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> paras;
        gen(paras,n,n,"");
        return paras;
    }
};