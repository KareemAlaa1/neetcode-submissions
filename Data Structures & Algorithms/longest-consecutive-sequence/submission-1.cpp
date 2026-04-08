class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int ans = 1;
        int currLong = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)currLong++;
            else if (nums[i]==nums[i-1])continue;
            else {
                ans = max(ans,currLong);
                currLong=1;
            }
        }
        ans = max(ans,currLong);
        return ans;
    }
};
