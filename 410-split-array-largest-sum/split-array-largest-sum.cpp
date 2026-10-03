class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());

        long long high = 0;
        for (int x : nums) {
            high += x;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int painters = 1;
            long long current = 0;

            for (int x : nums) {
                if (current + x <= mid) {
                    current += x;
                } else {
                    painters++;
                    current = x;
                }
            }

            if (painters <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};