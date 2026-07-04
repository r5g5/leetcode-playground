class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        constexpr static int N = 100001;
        vector<vector<pair<int, int>>> adjList(N, vector<pair<int, int>>());
        for (const auto& road : roads) {
            const auto u = road[0];
            const auto v = road[1];
            const auto w = road[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        queue<int> q;
        vector<int> dist(N, INT_MAX);

        q.push(1);

        while (!q.empty()) {
            auto u = q.front(); q.pop();
            // auto w = dist[u];
            for (auto& [v, w] : adjList[u]) {
                auto score = min(dist[u], w);
                if (score < dist[v]) {
                    // cout << "u: " << u << "->" << "v: " << v << "| w:" << w << endl;
                    // cout << "Score calc: " << score << "| dist[v]: " << dist[v] << "| dist[u]: " << dist[u] << endl;
                    dist[v] = score;
                    q.push(v);
                }
            }
        }

        return dist[n];
    }
};