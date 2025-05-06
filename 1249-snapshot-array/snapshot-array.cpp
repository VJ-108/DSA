class SnapshotArray {
public:
    vector<vector<pair<int,int>>> ans;
    int curr_snap = 0;
    SnapshotArray(int length) {
        ans.resize(length);
    }
    
    void set(int index, int val) {
        if (!ans[index].empty() && ans[index].back().first == curr_snap) {
            ans[index].back().second = val; 
        } else {
            ans[index].emplace_back(curr_snap, val);
        }
    }

    int snap() {
        return curr_snap++;
    }

    int get(int index, int snap_id) {
        const auto& vec = ans[index];
        int low = 0, high = vec.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].first <= snap_id) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res == -1 ? 0 : vec[res].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */