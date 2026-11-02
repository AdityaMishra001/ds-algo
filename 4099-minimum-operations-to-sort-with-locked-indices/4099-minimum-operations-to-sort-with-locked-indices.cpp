class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int ct = 0,l = 0, r = 0, k = low;
        vector<int> left(nums.begin() + low, nums.begin() + mid+1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + high+1);

        while (l < left.size() && r < right.size()) {
            if (left[l] <= right[r]) {
                nums[k++] = left[l++];
            } else {
                ct += left.size() - l;
                nums[k++] = right[r++];
            }
        }
        while (l < left.size())
            nums[k++] = left[l++];
        while (r < right.size())
            nums[k++] = right[r++];

        return ct;
    }
    int ct_inversions(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        return ct_inversions(nums, low, mid) +
               ct_inversions(nums, mid + 1, high) + 
               merge(nums, low, mid, high);
    }
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int operations = 0, n = nums.size();

        vector<bool> needed(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 == i)
                continue;
            // mark the range where we will. swap
            for (int j = min(nums[i]- 1,i); j<=max(nums[i]-1,i); j++){
                needed[j] = true;
            }
        }

        int req_unlocks = 0;
        for (int i = 0; i < n; i++) {
            req_unlocks += int(needed[i]&&locked[i]);
            if (req_unlocks > k)
                return -1;
        }
        operations = req_unlocks;

        for (int l = 0; l < n; l++) {
            if (!needed[l]) continue;
            int r = l;
            while (r + 1 < n && needed[r + 1])
                r++;
            vector<int>temp(nums.begin()+l,nums.begin()+r+1);
            operations += ct_inversions(temp, 0, temp.size()-1);
            l = r;
        }
        
        return operations;
    }
};