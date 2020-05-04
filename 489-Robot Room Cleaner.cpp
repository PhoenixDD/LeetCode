/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
static vector<int> dirs={-1,0,1,0,-1};
class Solution {
public:
    template <class T>
    static void hash_combine(std::size_t& seed,const T& v)
    {
        seed^=v+0x9e3779b9+(seed<<6)+(seed>>2);
    }
    struct pairhash
    {
        public:
        template <typename X, typename U>
        std::size_t operator()(const std::pair<X, U> &x) const
        {
            size_t hash = 0;
            hash_combine(hash,x.first);
            hash_combine(hash,x.second);
            return hash;
        }
    };
    unordered_set<pair<int,int>,pairhash> visited;
    void turnBack(Robot &r)
    {
        r.turnLeft();
        r.turnLeft();
        r.move();
        r.turnLeft();
        r.turnLeft();
    }
    void bt(Robot &r,int i,int j,int d)
    {
        visited.insert({i,j});
        r.clean();
        int newD,x,y;
        for(int dir=0;dir<4;dir++)
        {
            newD=(d+dir)%4;
            x=i+dirs[newD],y=j+dirs[newD+1];
            if(!visited.count({x,y})&&r.move())
            {
                bt(r,x,y,newD);
                turnBack(r);
            }
            r.turnRight();
        }
    }
    void cleanRoom(Robot& robot) 
    {
        return bt(robot,0,0,0);
    }
};