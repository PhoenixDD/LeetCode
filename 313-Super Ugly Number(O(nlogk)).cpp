typedef pair<int,pair<int,int>> iii;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        auto cmp=[](auto &l,auto &r){return l.first>r.first;};
        vector<int> result(n,1);
        priority_queue<iii,vector<iii>,decltype(cmp)> pq(cmp);
        iii temp;
        for(int &i:primes)
            pq.push({i,{0,i}});
        int index=1;
        while(--n)
        {
            while(!pq.empty()&&result[index-1]==result[pq.top().second.first]*pq.top().second.second)
                temp=pq.top(),pq.pop(),pq.push({result[temp.second.first+1]*temp.second.second,{temp.second.first+1,temp.second.second}});
            result[index]=result[pq.top().second.first]*pq.top().second.second;
            index++;
        }
        return result[index-1];
    }
};