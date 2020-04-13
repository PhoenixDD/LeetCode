class Solution {
public:
    //Get closest coordinate 
    int closestOnCircle(int center,int bl,int tr)
    {
        return max(min(center,tr),bl);
    }
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        int closestX=closestOnCircle(x_center,x1,x2);//Find the closest point to the circle within the rectangle
        int closestY=closestOnCircle(y_center,y1,y2);//Find the closest point to the circle within the rectangle
        int distanceX=x_center-closestX; //Find distance between closest point and center
        int distanceY=y_center-closestY;
        return distanceX*distanceX+distanceY*distanceY<=radius*radius;
        
    }
};