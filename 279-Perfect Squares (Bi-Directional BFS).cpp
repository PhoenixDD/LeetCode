class Solution {
public:
    int numSquares(int n) 
    {
        unordered_set<int> front,back,temp;
        unordered_set<int>::iterator it;
        front.insert(0);
        back.insert(n);
        int count=0;
        bool swap=false;
        while(!back.empty()&&!front.empty())
        {
            if(back.size()<front.size())
                front.swap(back),swap=!swap;
            for(it=front.begin();it!=front.end();it++)
            {
                if(back.count(*it))
                    return count;
                if(!swap)
                    for(int i=sqrt(n-*it);i>0;i--)
                        temp.insert(*it+i*i);
                else
                    for(int i=sqrt(*it);i>0;i--)
                        temp.insert(*it-i*i);
            }
            count++;
            front.swap(temp);
            temp.clear();
        }
    }
};