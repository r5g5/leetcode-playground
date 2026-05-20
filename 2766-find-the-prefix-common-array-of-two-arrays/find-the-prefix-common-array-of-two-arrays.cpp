class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        unordered_set<int> countA, countB;
        vector<int> C(n, 0);
        int commonPrefixLen = 0;
        for (int i = 0; i < n; i++) {
            countA.insert(A[i]);
            countB.insert(B[i]);

            if (A[i] == B[i]) {
                commonPrefixLen++;
            } else {
                if (countA.find(B[i]) != countA.end())
                    commonPrefixLen++;
                
                if (countB.find(A[i]) != countB.end())
                    commonPrefixLen++;
            }
            C[i] = commonPrefixLen;
        }
        return C;
    }
};