class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].push_front({tweetId,tweet_counter++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        map<int,pair<list<pair<int,int>>::iterator,int>,greater<int>> sorted_tweets;//Store tweets from all followees in sorted order of tweet # descending
        pair<list<pair<int,int>>::iterator,int> temp;
        for(auto it=follows[userId].begin();it!=follows[userId].end();it++)//Push all followees last tweet counter and list iterator with parent
            if(tweets.count(*it))
                sorted_tweets[tweets[*it].front().second]={tweets[*it].begin(),*it};
        if(tweets.count(userId))                                                            //Add user tweets if exists
            sorted_tweets[tweets[userId].front().second]={tweets[userId].begin(),userId};
        vector<int> result;
        for(int i=0;i<10&&!sorted_tweets.empty();i++)                                       //add 10 recent tweets
        {
            result.push_back(sorted_tweets.begin()->second.first->first);                   //Push the most recent tweet of all
            temp=sorted_tweets.begin()->second;
            sorted_tweets.erase(sorted_tweets.begin());
            if(++temp.first!=tweets[temp.second].end())                                     //Add next in the list if list has items
                sorted_tweets[temp.first->second]=temp;
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        follows[followerId].erase(followeeId);
    }
    private:
    unordered_map<int,unordered_set<int>> follows;              //Store followers-followees
    unordered_map<int,list<pair<int,int>>> tweets;              //Store Tweets with counter/Tweet# in sorted order of time recent-old
    int tweet_counter=0;                                        //Keeps increasing with every tweet
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */