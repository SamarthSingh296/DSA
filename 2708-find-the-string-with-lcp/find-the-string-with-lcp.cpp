class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<char> word(n, '#');
        char c = 'a';

        // Step 1: assign characters
        for (int i = 0; i < n; i++) {
            if (word[i] != '#') continue;

            if (c > 'z') return "";

            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = c;
                }
            }
            c++;
        }

        // Step 2: validate
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int expected = 0;

                if (word[i] == word[j]) {
                    if (i+1 < n && j+1 < n)
                        expected = 1 + lcp[i+1][j+1];
                    else
                        expected = 1;
                }

                if (lcp[i][j] != expected)
                    return "";
            }
        }

        return string(word.begin(), word.end());
    }
};