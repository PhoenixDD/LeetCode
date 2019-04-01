/*
Recursive Divide and conquer Solution : Find the letter which is repeated less than k times and divide the array into two parts removing that letter's index and recur on left and right and return the max Worst O(n^2) best O(nlogn)
*/
class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        if(k>s.length()||s.empty())
            return 0;
        if(k==0)
            return s.length();
        vector<int> count(256,0);
        for(char &c:s)
            count[c]++;
        int index=0,left;
        while(index<s.length()&&count[s[index]]>=k)
            index++;
        if(index==s.length())                       //All charaters are repeated k times (Base case).
            return s.length();
        left=index;
        while(index<s.length()&&s[index]==s[index+1]) //Find until that character is continued in the sequence to reduce recurence
            index++;
        return max(longestSubstring(s.substr(0,index),k),longestSubstring(s.substr(index+1),k));
    }
};