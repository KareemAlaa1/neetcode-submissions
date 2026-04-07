class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(auto i:strs){
            result += to_string(i.size());
            result += '?';
            result += i;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int currLen = 0;
        string currLenStr = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                currLen = stoi(currLenStr);
                string tempStr = "";
                while(currLen--){
                    tempStr+=s[++i];
                }
                result.push_back(tempStr);
                currLenStr = "";
            }
            else{
                currLenStr += s[i];
            }
        }

        return result;
    }
};
