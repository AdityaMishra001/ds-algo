class Solution {
    // const int size=1e5;
    // int dq[size];
    // int front,back;
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 64) {
            long long ct = 0;
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

        long long ct = 0, rem = k;
        deque<int> dq;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            int incoming = nums[l];

            while (!dq.empty() && nums[dq.front()] <= incoming) {
                int start = dq.front();
                dq.pop_front();
                int end = dq.empty() ? r + 1 : dq.front();
                rem -= 1LL * (end - start) * (incoming - nums[start]);
            }

            dq.push_front(l);

            while (rem < 0) {
                rem += nums[dq.back()] - nums[r];
                if (dq.back() == r) {
                    dq.pop_back();
                }
                r--;
            }

            ct += r - l + 1;
        }

        return ct;

        // front=back=n;
        // int r = n - 1;
        // for (int l = n - 1; l >= 0; l--) {
        //     int incoming=nums[l];
        //     while (front<back && nums[dq[front]] <= incoming) {
        //         int start=dq[front++];
        //         int end=(front==back)? r+1: dq[front];
        //         rem-=(end-start)*(incoming-nums[start]);
        //     }
        //     dq[--front]=l;

        //     while (rem<0) {
        //         rem+=nums[dq[back-1]]-nums[r];
        //         if(dq[back-1]==r)back--;
        //         r--;
        //     }

        //     ct += r - l + 1;
        // }

        return ct;
    }
};