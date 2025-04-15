class Solution {
    using ll = long long;
    vector<ll> seg_tree;  // Segment Tree to store frequency counts

    // Function to update the Segment Tree at a specific index
    void updateSegTree(ll st_idx, ll start, ll end, ll& query_idx) {
        if (end < query_idx || start > query_idx)
            return;  // Case 1: No overlap

        if (start == end) {
            // Case 2: Exact match (leaf node)
            seg_tree[st_idx]++;
            return;
        }

        // Case 3: Partial overlap, recurse into both children
        ll mid = start + (end - start) / 2;
        updateSegTree(2 * st_idx, start, mid, query_idx);
        updateSegTree(2 * st_idx + 1, mid + 1, end, query_idx);

        // Update current node based on children
        seg_tree[st_idx] = seg_tree[2 * st_idx] + seg_tree[2 * st_idx + 1];
    }

    // Function to query the sum in the range [qs, qe]
    int rangeSumQuery(ll st_idx, ll start, ll end, ll qs, ll qe) {
        if (qs > end || qe < start)
            return 0;  // Case 1: No overlap

        if (start >= qs && end <= qe)
            return seg_tree[st_idx];  // Case 2: Total overlap

        // Case 3: Partial overlap
        ll mid = start + (end - start) / 2;
        ll left_sum = rangeSumQuery(2 * st_idx, start, mid, qs, qe);
        ll right_sum = rangeSumQuery(2 * st_idx + 1, mid + 1, end, qs, qe);
        return left_sum + right_sum;
    }

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        seg_tree = vector<ll>(4 * n + 1, 0);  // Initialize segment tree

        // Step 1: Map each value in nums2 to its index
        unordered_map<ll, ll> nums2_val_idx;
        for (ll i = 0; i < n; ++i)
            nums2_val_idx[nums2[i]] = i;

        // Step 2: Start building segment tree from the first element in nums1
        updateSegTree(1, 0, n - 1, nums2_val_idx[nums1[0]]);

        ll count_good_triplets = 0;

        // Step 3: Consider each nums1[i] as the middle element of the triplet
        for (int i = 1; i < n - 1; ++i) {
            ll nums2_idx = nums2_val_idx[nums1[i]];

            // Count how many elements before nums1[i] are also before it in nums2
            ll common_left_elements = rangeSumQuery(1, 0, n - 1, 0, nums2_idx - 1);

            // Elements before i in nums1 that are not before in nums2
            ll uncommon_left_elements = i - common_left_elements;

            // Elements after nums1[i] in nums2 that are also after in nums1
            ll common_right_elements = (n - nums2_idx - 1) - uncommon_left_elements;

            // Multiply to count valid (i,j,k) triplets
            count_good_triplets += common_left_elements * common_right_elements;

            // Update segment tree with current index for next iteration
            updateSegTree(1, 0, n - 1, nums2_idx);
        }

        return count_good_triplets;
    }
};
