class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // If duplicate is found,
            // remove characters from the left
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            // Add current character
            st.insert(s[right]);

            // Calculate window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};