class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int nodes = arr.size();

        if (nodes == 1)
            return 0;

        unordered_map<int, vector<int>> valueToIdxMap;
        for (int i = 0; i < nodes; i++) {
            valueToIdxMap[arr[i]].emplace_back(i);
        }

        queue<int> q;
        vector<bool> visited(nodes, false);
        int steps = 0;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int sz = q.size();
            steps++;

            while (sz--) {
                int u = q.front(); q.pop();

                auto it = valueToIdxMap.find(arr[u]);
                
                // Same value
                if (it != valueToIdxMap.end()) {
                    for (const auto& v : it->second) {
                        if (v == nodes - 1) return steps;
                        else if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                    valueToIdxMap.erase(it);
                }

                // Index shift
                for (auto& v : {u - 1, u + 1}) {
                    if (v >= 0 && v < nodes && !visited[v]) {
                        if (v == nodes - 1) return steps;
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        return 0;

    }
};