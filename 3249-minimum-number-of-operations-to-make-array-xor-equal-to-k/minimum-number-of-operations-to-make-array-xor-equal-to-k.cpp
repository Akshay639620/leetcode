class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        for(int &n:nums){
            totalXor ^= n;
        }
        int diff = totalXor ^ k;
        return __builtin_popcount(diff);

    }
};