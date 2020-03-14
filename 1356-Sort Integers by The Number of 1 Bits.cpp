class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int &l,int &r){int x=__builtin_popcount(l),y=__builtin_popcount(r);return x==y?l<r:x<y;});
        return arr;
    }
};