/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int n;
    bool isCeleb(int candidate)
    {
        for(int i=0;i<n;i++)
            if(i!=candidate&&(knows(candidate,i)||!knows(i,candidate)))
                return false;
        return true;
    }
    int findCelebrity(int n)
    {
        this->n=n;
        int candidate=0;
        for(int i=0;i<n;i++)
            if(candidate!=i&&knows(candidate,i))
                candidate=i;
        return isCeleb(candidate)?candidate:-1;
                
    }
};