class Solution {
public:
    vector<vector<vector<int>>> memo;
    int removeBoxes(vector<int>& boxes,int i,int j,int k)
    {
        if(i>j)
            return 0;
        if(memo[i][j][k]!=-1)
            return memo[i][j][k];
        while(i<j&&boxes[i]==boxes[i+1])
            i++,k++;
        memo[i][j][k]=(k+1)*(k+1)+removeBoxes(boxes,i+1,j,0);
        for(int l=i+1;l<=j;l++)
            if(boxes[i]==boxes[l])
                memo[i][j][k]=max(memo[i][j][k],removeBoxes(boxes,i+1,l-1,0)+removeBoxes(boxes,l,j,k+1));
        return memo[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) 
    {
        memo.resize(boxes.size(),vector<vector<int>>(boxes.size(),vector<int>(boxes.size(),-1)));
        return removeBoxes(boxes,0,boxes.size()-1,0);
    }
};