class Solution {
private:
    vector<bool> visited;

    void dfs(vector<vector<int>>& list, const int u) {
        visited[u] = true;
        for (auto& v : list[u]) {
            if (!visited[v]) {
                dfs(list, v);
            }
        }
        return;
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n, vector<int>());
        visited.assign(n, false);

        for (auto& invocation : invocations) {
            adjList[invocation[0]].push_back(invocation[1]);
        }
        dfs(adjList, k);

        for (auto& invocation : invocations) {
            int a = invocation[0], b = invocation[1];
            if (visited[b] && !visited[a]) {
                vector<int> all(n);
                for (int i = 0; i < n; i++) all[i] = i;
                return all;
            }
        }

        vector<int> remainings;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                remainings.push_back(i);
            }
        }
        return remainings;

    }
};