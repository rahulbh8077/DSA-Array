class Solution {
public:
    void backtrack(int index, vector<int>& nums,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Store the current subset
        result.push_back(current);

        // Try including each remaining element
        for (int i = index; i < nums.size(); i++) {

            current.push_back(nums[i]);

            // Recursively generate subsets
            backtrack(i + 1, nums, current, result);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);

        return result;
    }
};