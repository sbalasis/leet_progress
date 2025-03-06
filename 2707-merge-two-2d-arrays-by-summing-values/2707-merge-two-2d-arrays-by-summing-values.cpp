class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
           int p1 = 0;
           int p1_size = nums1.size();
           int p2 = 0;
           int p2_size = nums2.size();
           int p3 = 0;
           vector<vector<int>> nums3;
           while(true)
           {
            if( (p1 == p1_size) || (p2 == p2_size))
            {
                break;
            }
            if(nums1[p1][0] < nums2[p2][0])
            {
                nums3.push_back(nums1[p1]);
                p1++;
            }
            else if(nums1[p1][0] > nums2[p2][0])
            {
                nums3.push_back(nums2[p2]);
                p2++;
            }
            else if(nums1[p1][0] == nums2[p2][0])
            {
                nums3.push_back(nums1[p1]);
                nums3[nums3.size()-1][1] += nums2[p2][1];
                p1++;
                p2++;
            }
            p3++;
           }

           if(p1 == p1_size && p2 == p2_size)
           {
            return nums3;
           }

           if(p1 == p1_size)
           {
            while(true)
            {
                if(p2 == p2_size)
                {
                    break;
                }
                nums3.push_back(nums2[p2]);
                p2++;
            }
            
           }
           else if(p2 == p2_size)
           {
            while(true)
            {
                if(p1 == p1_size)
                {
                    break;
                }
                nums3.push_back(nums1[p1]);
                p1++;
            }
           }
        return nums3;
    }
};