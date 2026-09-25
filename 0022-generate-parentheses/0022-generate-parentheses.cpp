class Solution {
public:
    void generate(int open, int close, int n, string current, vector<string>& ans) {
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add '(' if we still have opening brackets
        if (open < n) {
            generate(open + 1, close, n, current + '(', ans);
        }

        // Add ')' only if there are unmatched '('
        if (close < open) {
            generate(open, close + 1, n, current + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0, 0, n, "", ans);
        return ans;
    }
};
