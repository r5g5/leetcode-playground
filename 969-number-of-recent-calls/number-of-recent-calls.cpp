class RecentCounter {
    std::priority_queue<int, std::vector<int>, std::greater<int>> _frontier;
public:
    RecentCounter() {    
    }
    
    int ping(int t) {
        _frontier.push(t);
        while (!_frontier.empty()) {
            if (_frontier.top() < t - 3000) {
                _frontier.pop();
                continue;
            }
            break;
        }
        return _frontier.size(); // TC: O(nlogn), SC: O(n)
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */