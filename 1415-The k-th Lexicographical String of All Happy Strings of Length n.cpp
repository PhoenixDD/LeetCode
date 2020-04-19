static vector<int> pow2={1,2,4,8,16,32,64,128,266,512,1024};
class Solution {
public:
    string getHappyString(int n, int k,int pos=1,char notUse='x') 
    {
        if(k==0)
            return "";
        if(k>3&&pos==n)
            return "";
        int strStartingWith=0;
        char curr=notUse=='a'?'b':'a';
        if(pos==n)
            strStartingWith=k,curr+=k-1;
        else
            while(curr<='c'&&n-pos>=0&&strStartingWith+pow2[n-pos]<k)
            {
                strStartingWith+=pow2[n-pos];
                curr++;
                curr+=curr==notUse;
            }
        curr+=curr==notUse;
        return curr<='c'&&curr!=notUse?curr+getHappyString(n,k-strStartingWith,pos+1,curr):"";
    }
};