class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!= t.size())return false;
        vector <int> s_freq(26,0);
        vector <int> t_freq(26,0);
        for(int i=0;i<s.size();i++){
            s_freq[s[i]-'a']++;
            t_freq[t[i]-'a']++;
        }
        for(int i=0;i<s_freq.size();i++){
            if(s_freq[i]!=t_freq[i])return false;
        }
        return true;
        

    }
};
