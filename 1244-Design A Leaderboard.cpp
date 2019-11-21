class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) 
    {
        if(!leaderBoard.count(playerId))
            leaderBoard[playerId]=score,rLeaderBoard.insert(make_pair(score,playerId));
        else
        {
            it=rLeaderBoard.find(leaderBoard[playerId]);
            while(it->second!=playerId)
                it++;
            rLeaderBoard.erase(it);
            rLeaderBoard.insert(make_pair(leaderBoard[playerId]+score,playerId));
            leaderBoard[playerId]+=score;
        }
    }
    
    int top(int K) 
    {
        int sum=0;
        for(it2=rLeaderBoard.rbegin();it2!=rLeaderBoard.rend()&&K;it2++,K--)
            sum+=it2->first;
        return sum;
    }
    
    void reset(int playerId) 
    {
        it=rLeaderBoard.lower_bound(leaderBoard[playerId]);
        while(it!=rLeaderBoard.end()&&it->second!=playerId)
            it++;
        rLeaderBoard.erase(it);
        leaderBoard.erase(playerId);
    }
    private:
    multimap<int,int> rLeaderBoard;
    multimap<int,int>::iterator it;
    multimap<int,int>::reverse_iterator it2;
    unordered_map<int,int> leaderBoard;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */