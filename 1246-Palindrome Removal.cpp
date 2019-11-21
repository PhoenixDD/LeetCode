class Solution {
public:
    vector<vector<int>> memo;
    int dp(vector<int>& arr,int i,int j)
    {
        if(i>j)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        memo[i][j]=1+dp(arr,i+1,j);                     //1 number as a palindrome , also base case
        if(i<arr.size()-1&&arr[i]==arr[i+1])            //2 numbers as a palindrome also base case
            memo[i][j]=min(memo[i][j],1+dp(arr,i+2,j));
        for(int k=i+2;k<=j;k++)                         //i+2 because 2 numbers are covered before.
            if(arr[i]==arr[k])
                memo[i][j]=min(memo[i][j],dp(arr,i+1,k-1)+dp(arr,k+1,j)); //No +1 here since we are considering it to be a palindrome.
        return memo[i][j];
    }
    int minimumMoves(vector<int>& arr) 
    {
        memo.resize(arr.size(),vector<int>(arr.size(),-1));
        return dp(arr,0,arr.size()-1);
    }
};