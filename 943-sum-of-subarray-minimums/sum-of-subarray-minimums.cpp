class Solution {
public:
    vector<int> findNse(vector<int> a) {
        int n = a.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPse(vector<int> a) {
        int n = a.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] > a[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long  mod = (1e9 + 7);
        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + left * right * 1LL * arr[i]) % mod;
        }
        return total;
    }
};