class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int subsets = 1 << n;
        for (int integer = 0; integer < subsets; integer++) {
            vector<int> list;
            for (int i = 0; i < n; i++) {
                if (integer & (1 << i)) {
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};