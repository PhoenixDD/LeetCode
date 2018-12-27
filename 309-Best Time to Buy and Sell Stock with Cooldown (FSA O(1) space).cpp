//Using finite state Automata/Machine (FSA/FSM)
//state0=first state(No hold) -> state1 (if buy) -> state2 (if sell) can do nothing at state0 and state1
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()<=1)
            return 0;
        int state0,state1,state2,prevstate0,prevstate1,prevstate2;      
        prevstate0=0;
        prevstate1=-prices[0];
        prevstate2=INT_MIN;
        for(int i=1;i<prices.size();i++)
        {
            state0=max(prevstate0,prevstate2);
            state1=max(prevstate1,prevstate0-prices[i]);
            state2=prevstate1+prices[i];
            prevstate0=state0,prevstate1=state1,prevstate2=state2;
        }
        return max(state0,state2);
    }
};