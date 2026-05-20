class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        unordered_set<int> count;
        vector<int> C(n, 0);
        for (int i = 0; i < n; i++) {
            count.insert(A[i]);
            int commPrefix = 0;
            for (int j = 0; j <= i; j++) {
                if (count.find(B[j]) != count.end())
                    commPrefix++;
            }
            C[i] = commPrefix;
        }
        return C;
    }
};