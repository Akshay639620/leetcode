class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s1, s2;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            while (!s2.empty() && nums[s2.top()] < nums[i]) {
                ans[s2.top()] = nums[i];
                s2.pop();
            }
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                temp.push_back(s1.top());
                s1.pop();
            }
            for (int j = temp.size() - 1; j >= 0; j--) {
                s2.push(temp[j]);
            }
            temp.clear();
            s1.push(i);
        }
        return ans;
    }
};