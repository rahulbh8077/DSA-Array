class Solution {
public:
    vector<string> result;

    string phone[10] = {
        "",     "",     "abc",  "def",
        "ghi",  "jkl",  "mno",  "pqrs",
        "tuv",  "wxyz"
    };

    void backtrack(string &digits, int index, string &current) {
        // Base case
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to current digit
        string letters = phone[digits[index] - '0'];

        for (char ch : letters) {
            // Choose
            current.push_back(ch);

            // Explore
            backtrack(digits, index + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        string current;
        backtrack(digits, 0, current);

        return result;
    }
};