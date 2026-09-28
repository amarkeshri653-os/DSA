class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long sum = 0;

            for (int x : nums) {
                sum += (x + mid - 1) / mid;
            }

            if (sum <= threshold) {
                // mid works, try to find a smaller divisor
                high = mid - 1;
            } else {
                // mid is too small
                low = mid + 1;
            }
        }

        return low;
    }
};