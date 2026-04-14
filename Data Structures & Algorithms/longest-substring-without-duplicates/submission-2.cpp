class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        if(s.size()<1)return 0;
        int start = 0;
        int end = 0;
        int ans = 1;
        freq[s[0]] = 1;
        while(++end<s.size()){
            freq[s[end]]++;
            while(freq[s[end]]>1)freq[s[start++]]--;
            ans = max(ans,end-start+1);
        }
        return ans;
    }
};
