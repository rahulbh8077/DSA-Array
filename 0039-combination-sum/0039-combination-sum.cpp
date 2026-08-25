class Solution {
public:

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {

        // Target reached
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Target exceeded
        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Choose
            current.push_back(candidates[i]);

            // Explore
            solve(candidates, target - candidates[i],
                  i, current, ans);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};