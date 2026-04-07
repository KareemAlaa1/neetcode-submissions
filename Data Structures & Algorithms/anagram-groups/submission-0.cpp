class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<int>> hashMap;
        for(int i=0;i<strs.size();i++){
            vector<int>strMap (26,0);
            for(int j=0;j<strs[i].size();j++){
                strMap[strs[i][j]-'a']++;
            }
            string tempStr="";
            for(int j=0;j<strMap.size();j++){
                tempStr += char('a' + j);
                tempStr += to_string(strMap[j]);
            }
            hashMap[tempStr].push_back(i);
        }
        vector<vector<string>> result;
        for(auto i:hashMap){
            vector<string> tempVec;
            for(auto j:i.second){
                tempVec.push_back(strs[j]);
            }
            result.push_back(tempVec);
        }

        return result;
    }
};
