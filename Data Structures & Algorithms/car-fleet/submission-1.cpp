class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> temp;
        for(int i = 0; i < position.size(); i++){
            temp.push_back({position[i], speed[i]});
        }

        sort(temp.begin(), temp.end());

        int ans = 1;

        long long t_max = target - temp.back().first;
        long long s_max = temp.back().second;

        for(int i = temp.size() - 2; i >= 0; i--){
            long long t_cur = target - temp[i].first;
            long long s_cur = temp[i].second;

            if(t_cur * s_max > t_max * s_cur){
                ans++;
                t_max = t_cur;
                s_max = s_cur;
            }
        }

        return ans;
    }
};