class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int size = n * n;
        vector<int> ans(2, 0);
        vector<int> arr(size, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[grid[i][j]-1]++;
            }
        }

        for(int i = 0; i < size; i++)
        {
            if(arr[i] == 2)
            {
                ans[0] = i+1;
            }
            else if(arr[i] == 0)
            {
                ans[1] = i+1;
            }
        }

        return ans;

    }
};