class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> hashMap;
        for(auto i:nums)hashMap[i]++;

        vector<pair<int,int>> freq;
        for(auto key:hashMap)freq.push_back({key.second, key.first});

        sort(freq.begin(), freq.end());

        vector<int> result; 
        for(int i=freq.size()-1;i>(int)freq.size()-1-k;i--)result.push_back(freq[i].second);
        return result;
    }
};
