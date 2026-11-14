class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ct = 0;
        if (n < 60) {
            for (int l = 0; l < n; l++) {
                long long need = k;
                long long maxSoFar = nums[l];
                
                for (int r = l; r < n; r++) {
                    if (maxSoFar > nums[r]) {
                        need -= (maxSoFar - nums[r]);
                        if (need < 0) {
                            break; 
                        }
                    } else {
                        maxSoFar = nums[r]; 
                    }
                    ct++;
                }
            }
            return ct;
        }

        int r = n - 1;
        deque<pair<int, int>> dq;
        long long currCost = 0;
        for (int l = n - 1; l >= 0; l--) {
            int incoming = nums[l];
            int freq = 1;
            while (!dq.empty() && dq.front().first <= incoming) {
                auto [ele, f] = dq.front();
                dq.pop_front();
                currCost += 1LL * f * (incoming - ele);
                freq += f;
            }

            dq.push_front({incoming, freq});

            while (currCost > k) {
                int outgoing = nums[r--];
                auto [ele, f] = dq.back();
                currCost -= ele - outgoing;
                if (--dq.back().second == 0)
                    dq.pop_back();
            }

            ct += r - l + 1;
        }

        return ct;
    }
};