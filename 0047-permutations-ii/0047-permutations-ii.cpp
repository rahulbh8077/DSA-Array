class Solution {
public:
    void solve(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& current,
               vector<bool>& used) {

        // If permutation is complete
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used in current permutation
            if (used[i])
                continue;

            // Skip duplicates at the same level
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            current.push_back(nums[i]);
            used[i] = true;

            solve(nums, ans, current, used);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);

        solve(nums, ans, current, used);

        return ans;
    }
};