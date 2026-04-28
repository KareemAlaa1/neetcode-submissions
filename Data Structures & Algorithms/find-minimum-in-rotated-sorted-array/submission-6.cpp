class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        int l = 1;
        int r = nums.size()-1;
        int mid = 0;
        while(l<r){
            mid = l + (r-l)/2;
            if(nums[mid]>ans){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return min(ans,nums[l]);
    }
};
