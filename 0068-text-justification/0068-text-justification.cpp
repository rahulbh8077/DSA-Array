class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // Find how many words can fit in this line
            while (j < n) {
                int required = lineLength + words[j].size();

                // If it's not the first word, we need at least one space
                if (j > i)
                    required += (j - i);

                if (required > maxWidth)
                    break;

                lineLength += words[j].size();
                j++;
            }

            int wordCount = j - i;
            bool lastLine = (j == n);

            string line;

            // Last line OR line contains only one word
            if (lastLine || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += " ";

                    line += words[k];
                }

                // Left justify
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Total spaces that need to be distributed
                int totalSpaces = maxWidth - lineLength;

                // Number of gaps between words
                int gaps = wordCount - 1;

                int spacesEach = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        // First 'extraSpaces' gaps get one additional space
                        int spaces = spacesEach;

                        if (k - i < extraSpaces)
                            spaces++;

                        line += string(spaces, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
