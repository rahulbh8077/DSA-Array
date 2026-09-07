class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = true;

        for (char ch : s) {

            rows[currentRow] += ch;

            // Change direction at top and bottom
            if (currentRow == numRows - 1) {
                goingDown = false;
            }
            else if (currentRow == 0) {
                goingDown = true;
            }

            if (goingDown) {
                currentRow++;
            }
            else {
                currentRow--;
            }
        }

        string ans = "";

        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};