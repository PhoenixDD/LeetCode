/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
//Divide the rectangle into 4 quadrants recursivly. O(logn)
class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) 
    {
        if(topRight.front()<bottomLeft.front()||topRight.back()<bottomLeft.back()||!sea.hasShips(topRight,bottomLeft))
            return 0;
        if(topRight==bottomLeft)
            return 1;
        int midX=(topRight.front()+bottomLeft.front())/2,midY=(topRight.back()+bottomLeft.back())/2;
         return countShips(sea,{midX,midY},bottomLeft)+countShips(sea, topRight,{midX+1,midY+1})+countShips(sea,{midX,topRight.back()},{bottomLeft.front(),midY+1})+countShips(sea,{topRight.front(),midY},{midX+1,bottomLeft.back()});
    }
};