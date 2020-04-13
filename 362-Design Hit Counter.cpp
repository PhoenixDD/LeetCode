class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) 
    {
        if(times[timestamp%300]==timestamp)
            hits[timestamp%300]++;
        else
            hits[timestamp%300]=1,times[timestamp%300]=timestamp;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) 
    {
        int result=0;
        for(int i=0;i<300;i++)
            if(timestamp-times[i]<300)
                result+=hits[i];
        return result;
    }
    private:
    vector<int> times{vector<int>(300,0)},hits{vector<int>(300,0)};
    
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */