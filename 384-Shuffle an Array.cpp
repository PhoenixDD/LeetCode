//Fisher-Yates Algorithm
class Solution {
public:
    Solution(vector<int> nums) {
        original=randomized=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=randomized.size()-1;i>0;i--)
            swap(randomized[rand()%(i+1)],randomized[i]);
        return randomized;
    }
    private:
    vector<int> original,randomized;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */