class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> activeAsteroids;
        for (const auto& asteroid : asteroids) {
            bool shouldInsert = true;
            while (!activeAsteroids.empty()) {
                int topAsteroid = activeAsteroids.top();
                if (topAsteroid > 0 && asteroid < 0) {
                    // opposite direction, smaller one needs to be removed
                    if (abs(topAsteroid) > abs(asteroid)) {
                        shouldInsert = false;
                        break;
                    } else if (abs(topAsteroid) == abs(asteroid)) {
                        activeAsteroids.pop();
                        shouldInsert = false;
                        break;
                    } else {
                        activeAsteroids.pop();
                    }
                } else {
                    break;
                }
            }
            if (shouldInsert) {
                activeAsteroids.push(asteroid);
            }
        }
        asteroids.clear();
        while (!activeAsteroids.empty()) {
            asteroids.push_back(activeAsteroids.top());
            activeAsteroids.pop();
        }
        reverse(asteroids.begin(), asteroids.end());
        return asteroids; // TC: O(n^2), SC: O(n)
    }
};