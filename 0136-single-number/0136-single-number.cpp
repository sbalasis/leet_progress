class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < nums.size(); i += 2)
        {
            if(i+1 == nums.size() )
            {
                break;
            }
            else if(nums[i]!=nums[i+1])
            {
                break;
            }
        }
        return nums[i];
    }
};