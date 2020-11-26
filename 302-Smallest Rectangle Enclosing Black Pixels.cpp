class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y)
    {
        int left=getCol(image,0,image.size(),0,y,true);
        int right=getCol(image,0,image.size(),y+1,image[0].size(),false);
        int top=getRow(image,0,x,left,right,true);
        int bottom=getRow(image,x+1,image.size(),left,right,false);
        return (right-left)*(bottom-top);
    }
    int getCol(vector<vector<char>>& image,int top,int bottom,int left,int right,bool findWhite)
    {
        int k,mid;
        while(left<right)
        {
            mid=(left+right)>>1;
            k=top;
            while(k<bottom&&'0'==image[k][mid])
                k++;
            if(k<bottom==findWhite)     //findWhite?lower_bound:upper_bound
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
    int getRow(vector<vector<char>>& image,int top,int bottom,int left,int right,bool findWhite)
    {
        int k,mid;
        while(top<bottom)
        {
            mid=(top+bottom)>>1;
            k=left;
            while(k<right&&'0'==image[mid][k])
                k++;
            if(k<right==findWhite)
                bottom=mid;
            else
                top=mid+1;
        }
        return top;
    }
};