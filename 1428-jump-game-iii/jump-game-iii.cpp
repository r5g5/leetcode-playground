class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) return true;
        const int n = arr.size();
        queue<pair<int, int>> q;
        vector<int> visited;
        visited.resize(n, false);
        q.push({start, arr[start]});
        visited[start] = true;
        // bool found = false;
        while (!q.empty()) {
            auto top = q.front(); q.pop();
            int forward  = top.first + top.second;
            int backward = top.first -  top.second;
            if (forward >= 0 && forward < n && !visited[forward]) {
                visited[forward] = true;
                if (arr[forward] == 0)
                    return true;
                q.push({forward, arr[forward]});
            }
            if (backward >= 0 && backward < n && !visited[backward]) {
                visited[backward] = true;
                if (arr[backward] == 0)
                    return true;
                q.push({backward, arr[backward]});
            }
        }
        return false;
    }
};