static int maxMin=60*24;
class Solution {
public:
    vector<int> digits,validCombinations;
    void backTrack(int d,int curr)
    {
        if(d==2)
            validCombinations.push_back(curr);
        for(int &i:digits)
            if(d==0&&i<6||d==1)
                backTrack(d+1,curr*10+i);
    }
    int getDiff(int hour1,int min1,int hour2,int min2)
    {
        return (60*hour2+min2-60*hour1-min1+maxMin)%maxMin;
    }
    string nextClosestTime(string time) 
    {
        digits={time[0]-'0',time[1]-'0',time[3]-'0',time[4]-'0'},validCombinations;
        int min=(time[3]-'0')*10+time[4]-'0',hour=(time[0]-'0')*10+time[1]-'0',Min=maxMin,resMin=-1,resHour=-1,diff;
        backTrack(0,0);
        sort(validCombinations.begin(),validCombinations.end());
        for(int i=0;i<validCombinations.size()&&validCombinations[i]<24;i++)
            for(int &j:validCombinations)
            {
                diff=getDiff(hour,min,validCombinations[i],j);
                if(diff!=0&&diff<Min)
                    Min=diff,resMin=j,resHour=validCombinations[i];
            }
        return resMin==-1?time:(resHour<10?"0":"")+to_string(resHour)+":"+(resMin<10?"0":"")+to_string(resMin);
    }
};