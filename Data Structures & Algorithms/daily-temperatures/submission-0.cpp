class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0;i<temperatures.size();i++){
            if(st.empty()){
                st.push({temperatures[i],i});
                continue;
            }else{
                while(!st.empty() && st.top().first < temperatures[i]){
                    auto temp = st.top();
                    st.pop();
                    ans[temp.second] = i-temp.second;
                }
                st.push({temperatures[i],i});
            }
        }
        return ans;
    }
};
