class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) 
    {
        vector<int> result;
        int count=0;
        for(int i=0;i<sideLength;i++)                          //Get how many times each location of submatrix is repeated in bigger matrix
            for(int j=0;j<sideLength;j++)
                result.push_back(((width-j-1)/sideLength+1)*((height-i-1)/sideLength+1));
        sort(result.begin(),result.end(),greater<int>());       //Sort the locations in descending order
        for(int i=0;i<maxOnes;i++)                              //Add the locations i.e number of ones required
            count+=result[i];
        return count;
    }
};