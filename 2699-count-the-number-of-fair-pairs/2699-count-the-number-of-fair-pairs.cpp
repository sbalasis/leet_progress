#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end()); // Step 1: Sort nums
        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int low = lower - nums[i]; // Minimum value needed for nums[j]
            int high = upper - nums[i]; // Maximum value allowed for nums[j]

            // Use binary search to find the valid range
            int left = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), high) - nums.begin();

            count += (right - left); // Count valid pairs for nums[i]
        }

        return count;
    }
};
