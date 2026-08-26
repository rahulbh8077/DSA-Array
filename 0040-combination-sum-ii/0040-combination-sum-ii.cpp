class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {

        // Target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Target exceeded
        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate elements at the same level
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted
            if (candidates[i] > target) {
                break;
            }

            // Choose
            current.push_back(candidates[i]);

            // Move to i + 1 because each element
            // can be used only once
            solve(candidates, target - candidates[i],
                  i + 1, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        vector<vector<int>> ans;
        vector<int> current;

        // Sort to handle duplicates
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};