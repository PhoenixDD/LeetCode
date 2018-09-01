class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int area=(D-B)*(C-A)+(H-F)*(G-E);
        if(A>G||E>C||B>H||F>D)
            return area;
        int a=A>E?A:E,b=B>F?B:F,c=C<G?C:G,d=D<H?D:H;
        return area-(d-b)*(c-a);
    }
};