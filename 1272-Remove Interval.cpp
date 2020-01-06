class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
    {
        vector<vector<int>> result;
        for(vector<int> &interval:intervals)
        {
            if(interval.back()<=toBeRemoved.front()||interval.front()>=toBeRemoved.back())
                result.push_back(interval);
            else
            {
                if(interval.front()<toBeRemoved.front())
                    result.push_back({interval.front(),toBeRemoved.front()});
                if(interval.back()>toBeRemoved.back())
                    result.push_back({toBeRemoved.back(),interval.back()});
            }
        }
        return result;
    }
};