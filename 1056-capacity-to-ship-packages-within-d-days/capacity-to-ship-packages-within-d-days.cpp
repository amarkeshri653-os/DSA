class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int low = *max_element(w.begin(), w.end());

        int high = 0;
        for (int x : w) {
            high += x;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int days = 1;
            int load = 0;

            for (int x : w) {
                if (load + x > mid) {
                    days++;
                    load = x;
                }
                else {
                    load += x;
                }
            }

            if (days <= d) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};