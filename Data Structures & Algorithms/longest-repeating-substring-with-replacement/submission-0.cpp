class Solution {
public:
    int characterReplacement(string s, int k) {
        int temp = k;
        int ans = 0;
        int start = 0;
        for (char i= 'A';i<='Z';i++){
            start = 0;
            k = temp;
            for(int j=0;j<s.size();j++){
                if(s[j]==i)continue;
                else{
                    if(k--<=0){
                        ans = max(ans, j-start);
                        while(s[start]==i)start++;
                        start++;
                        k++;
                    }
                }
            }
            ans = max(ans, (int)s.size()-start);

        }
        return ans;
    }
};
