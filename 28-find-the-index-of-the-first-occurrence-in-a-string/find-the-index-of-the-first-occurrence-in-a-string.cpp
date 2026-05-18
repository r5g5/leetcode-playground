class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        
        const int n = haystack.size(), m = needle.size();
        vector<int> lps(m, 0);

        int prevLPS = 0, i = 1;

        while (i < m) {
            if (needle[i] == needle[prevLPS]) {
                lps[i] = prevLPS + 1;
                prevLPS++;
                i++;
            } else {
                if (prevLPS == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    prevLPS = lps[prevLPS - 1];
                }
            }
        }

        i = 0; // pointer for haystack
        int j = 0; // pointer for needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j-1];
                }
            }

            if (j == m) {
                return i - m;
            }
        }

        return -1;

    }
};