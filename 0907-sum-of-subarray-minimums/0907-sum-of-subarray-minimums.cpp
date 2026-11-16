class Solution {
public:
    static int const MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        stack<int> st;

        for (int r = 0; r <= n; r++) {
            while (!st.empty() && (r == n || arr[st.top()] >= arr[r])) {
                int i = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                ans = (ans + 1LL * arr[i] * (r-i)*(i-l) % MOD) % MOD;
            }

            if (r <= n)
                st.push(r);
        }

        return ans;
    }
};