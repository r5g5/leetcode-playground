class Solution {
public:
    bool closeStrings(string word1, string word2) {
        const int len1 = word1.size(), len2 = word2.size();

        if (len1 != len2)
            return false;

        unordered_map<char, int> count1, count2;

        for (const auto& ch : word1) {
            count1[ch]++;
        }

        for (const auto& ch : word2) {
            if (!word1.contains(ch))
                return false;
            
            count2[ch]++;
        }

        vector<int> val1, val2;

        for (auto& [ch, freq] : count1) {
            val1.push_back(freq);
        }

        for (auto& [ch, freq] : count2) {
            val2.push_back(freq);
        }

        sort(val1.begin(), val1.end());
        sort(val2.begin(), val2.end());

        if (val1.size() != val2.size()) return false;

        for (int i=0; i < val1.size(); i++) {
            if (val1[i] != val2[i])
                return false;
        }

        return true; // TC: O(nlogn), SC: O(n)
    }
};