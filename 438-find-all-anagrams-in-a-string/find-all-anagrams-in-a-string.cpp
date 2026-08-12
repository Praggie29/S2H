class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagramsIndices;
        int n = s.size();
        int m = p.size();

        if (n < m) return anagramsIndices;

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);
        int idx = 0;
        while (idx < m) {
            pFreq[p[idx] - 'a']++;
            idx++;
        }

        int i = 0, j = 0;
        while (j < n) {
            windowFreq[s[j] - 'a']++;
            if (j - i + 1 == m) {
                if (windowFreq == pFreq) {
                    anagramsIndices.push_back(i);
                }
                windowFreq[s[i] - 'a']--;
                i++;
            }
            j++;
        }

        return anagramsIndices;
    }
};