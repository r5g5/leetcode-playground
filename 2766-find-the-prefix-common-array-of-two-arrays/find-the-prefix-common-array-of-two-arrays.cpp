class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        const int n = A.size();
        int commonPrefixLen = 0;
        
        for (int i = 0; i < n; i++) {
            int freq1 = ++mp[A[i]];
            int freq2 = ++mp[B[i]];

            if (freq1 == 2)
                commonPrefixLen++;
            
            if (freq2 == 2)
                commonPrefixLen++;
            
            A[i] = commonPrefixLen;

        }

        return A;
    }
};