class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)return 0;
        int curr = 0;
        int between = 0;
        int ans = 0;
        for(int i=1;i<height.size();i++){
            if(height[i]<height[curr])between+=height[i];
            else {
                ans+=min(height[i], height[curr])*(i-curr-1)-between;
                between = 0;
                curr = i;
            }
        }
        int temp = curr;
        curr = height.size()-1;
        between = 0;
        for(int i=height.size()-2;i>=temp;i--){
            if(height[i]<height[curr])between+=height[i];
            else {
                ans+=min(height[i], height[curr])*(curr-i-1)-between;
                between = 0;
                curr = i;
            }
        }
        return ans;
    }
};
