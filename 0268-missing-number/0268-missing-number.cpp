class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        for(i = 0; i < nums.size(); i++)
        {
            if(i != nums[i])
            {
                return i;
            }
        }
        return i;
    }
};