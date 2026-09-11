class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& current, vector<bool>& used) {

        // If permutation is complete
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every element
        for (int i = 0; i < nums.size(); i++) {

            // Skip already used element
            if (used[i]) {
                continue;
            }

            // Choose
            current.push_back(nums[i]);
            used[i] = true;

            // Explore
            solve(nums, ans, current, used);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        solve(nums, ans, current, used);

        return ans;
    }
};