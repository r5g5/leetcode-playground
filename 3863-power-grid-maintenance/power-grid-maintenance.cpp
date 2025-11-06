class Solution {
private:
    vector<vector<int>> _scc;
    void dfs(vector<vector<int>>& graph, int source, vector<int>& cc, vector<bool>& used) {
        used[source] = true;
        cc.push_back(source);
        for (auto& v : graph[source]) {
            if (!used[v]) {
                dfs(graph, v, cc, used);
            }
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(c+1);
        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> used(c+1, false);
        for (int u = 1; u <= c; u++) {
            if (!used[u]) {
                vector<int> tmp;
                dfs(adjList, u, tmp, used);
                _scc.push_back(tmp);
            }
        }

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeap;

        unordered_map<int, uint32_t> nodeToGroupIDMap;
        int id = 0;

        for (auto& cc : _scc) {
            for (int& node : cc) {
                nodeToGroupIDMap[node] = id;
                minHeap[id].push(node);
            }
            id++;
        }

        unordered_set<int> offlineSystems;
        vector<int> ans;


        for (auto& query : queries) {
            int x = query[1];
            if (query[0] == 1) {
                if (offlineSystems.find(x) == offlineSystems.end()) {
                    ans.push_back(x);
                } else {
                    // 1. Find the component in which it belongs
                    id = nodeToGroupIDMap[x];
                    // 2. Retrieve the smallest element as soon as possible
                    int value = -1;
                    while (!minHeap[id].empty()) {
                        int sys = minHeap[id].top(); minHeap[id].pop();
                        if (offlineSystems.find(sys) == offlineSystems.end()) {
                            value = sys;
                            break;
                        }
                    }

                    if (value != -1) {
                        minHeap[id].push(value);
                    }

                    ans.push_back(value);

                    // for (auto& sys : _scc[id]) {
                    //     if (offlineSystems.find(sys) == offlineSystems.end()) {
                    //         value = sys;
                    //         break;
                    //     }
                    // }
                    // ans.push_back(value);
                }
            } else {
                offlineSystems.insert(x);
            }
        }

        return ans;
    }
};