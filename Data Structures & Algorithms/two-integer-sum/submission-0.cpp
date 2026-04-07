class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indexMap.find(diff) != indexMap.end()) {
                return {indexMap[diff], i};
            }
            indexMap.insert({nums[i], i});
        }
        return {};
    }
};