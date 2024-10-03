class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long long total_sum = 0;
        for (int num : nums) 
        {
            total_sum += num;  // Calculate total sum
        }
        if(total_sum < p) return -1; 
        long long target = total_sum % p;  // Target sum we need to remove
        if (target == 0) return 0;  // Already divisible by p, remove no elements

        std::unordered_map<long long, int> prefix_sum_map;  // Prefix sums to indices
        prefix_sum_map[0] = -1;  // Handle case when subarray starts from index 0
        long long current_sum = 0;
        int min_length = nums.size() + 1;  // Initialize to a large value

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            current_sum += nums[i];  // Update current prefix sum

            // Check if there is a prefix sum that satisfies the condition
            long long needed_prefix_sum = (current_sum - target + p) % p;
            if (prefix_sum_map.count(needed_prefix_sum)) {
                min_length = std::min(min_length, i - prefix_sum_map[needed_prefix_sum]);
            }

            // Store the current prefix sum with its index
            prefix_sum_map[current_sum % p] = i;
        }

        min_length == nums.size() + 1 ? -1 : min_length;  // Return result
        if(min_length == nums.size())
        {
            return -1;
        }
        else
        {
            return min_length;
        }
    }
};