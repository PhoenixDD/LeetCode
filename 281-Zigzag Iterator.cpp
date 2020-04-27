//Follow-up answer: This can be extended to k lists with vector of iterators in O(1) time.
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) 
    {
        if(grid.empty()||grid[0].empty())
            return 0;
        vector<vector<int>> up(grid.size(),vector<int>(grid[0].size(),0)),down(grid.size(),vector<int>(grid[0].size(),0)),left(grid.size(),vector<int>(grid[0].size(),0)),right(grid.size(),vector<int>(grid[0].size(),0));
        int result=0;
        for(int j=0;j<grid[0].size();j++)
            for(int i=1;i<grid.size();i++)
                if(grid[i][j]=='W')
                    up[i][j]=0;
                elseclass ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) 
    {
        isFirst=!v1.empty()?true:false;
        it1=v1.begin();
        it2=v2.begin();
        end1=v1.end();
        end2=v2.end();
    }

    int next() 
    {
        if(isFirst)
        {
            temp=*it1;
            it1++;
            if(it2!=end2)
                isFirst=false;
        }
        else
        {
            temp=*it2;
            it2++;
            if(it1!=end1)
                isFirst=true;
        }
        return temp;
    }

    bool hasNext() 
    {
        return it1!=end1||it2!=end2;
    }
    private:
    bool isFirst;
    vector<int>::iterator it1,it2,end1,end2;
    int temp;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */