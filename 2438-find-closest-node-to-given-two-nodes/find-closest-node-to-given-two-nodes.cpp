class Solution {
public:
    void computeDistances(const vector<int>& edges, int start, vector<int>& dist) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int d = 0;
        while (start != -1 && !visited[start]) {
            dist[start] = d++;
            visited[start] = true;
            start = edges[start];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        computeDistances(edges, node1, dist1);
        computeDistances(edges, node2, dist2);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};
