class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> freq(128, 0);

        for (char c : t) freq[c]++;

        int left = 0, right = 0;
        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            // include current char in window
            if (freq[s[right]] > 0) {
                required--;
            }
            freq[s[right]]--;
            right++;

            // when valid window found
            while (required == 0) {
                // update answer
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // try shrinking from left
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    required++; // window no longer valid
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};