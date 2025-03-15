class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        auto canRob = [&](int cap) {
            int count = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (nums[i] <= cap) {
                    count++;
                    i++;  // Skip the next house
                }
                if (count >= k) return true;
            }
            return false;
        };

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canRob(mid)) {
                right = mid;  // Try to minimize the capability
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
