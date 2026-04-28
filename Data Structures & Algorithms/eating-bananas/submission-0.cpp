class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        int mid = 0;

        while (l <= r) {
            mid = l + (r-l)/2;

            long long int totalTime = 0;
            for (int p : piles) {
                totalTime += (p + mid - 1) / mid;
            }
            if (totalTime <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};