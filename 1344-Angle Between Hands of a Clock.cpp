//hourAngle=360/12 *1/60, minAngle=360/60.
class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        double hourAngle=0.5,minAngle=6,angle=abs(hourAngle*(60*(hour%12)+minutes)-minAngle*minutes);
        return min(360-angle,angle);
    }
};