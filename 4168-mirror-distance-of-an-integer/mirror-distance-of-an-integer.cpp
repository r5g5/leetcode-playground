class Solution {
public:
    int mirrorDistance(int n) {
       auto s = to_string(n);
       reverse(s.begin(), s.end());
       return abs(n - stoi(s)); 
    }
};