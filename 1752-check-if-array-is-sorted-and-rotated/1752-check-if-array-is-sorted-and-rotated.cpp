class Solution {
public:
    bool check(vector<int>& nums) {

        bool flag = 0;
        int n = nums.size();

        if (n == 1 || n == 2)
            return 1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (flag)
                    return 0;
                flag = 1;
            }
        }

        return !flag|| (nums[0] >= nums[n - 1]);
    }
};