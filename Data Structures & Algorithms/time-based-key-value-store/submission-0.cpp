class TimeMap {
public:
    unordered_map<string, vector<int>> times;
    unordered_map<string, vector<string>> values;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        times[key].push_back(timestamp);
        values[key].push_back(value);
    }

    string get(string key, int timestamp) {
        if (times.find(key) == times.end()) return "";

        vector<int>& t = times[key];
        vector<string>& v = values[key];

        int l = 0, r = t.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (t[mid] <= timestamp) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans == -1 ? "" : v[ans];
    }
};