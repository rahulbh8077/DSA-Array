class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;

            // Sort the string to create a common key
            sort(key.begin(), key.end());

            // Add original string to its anagram group
            mp[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto &pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};