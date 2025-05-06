class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mpp.find(key) == mpp.end()) return "";
        const auto& vec = mpp[key];
        int left = 0, right = vec.size() - 1;
        string res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */