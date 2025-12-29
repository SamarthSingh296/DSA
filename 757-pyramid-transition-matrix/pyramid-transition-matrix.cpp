class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad;

    bool solve(const string &row) {
        if (row.size() == 1) return true;
        if (bad.count(row)) return false;

        vector<string> nextRows;
        buildNextRows(row, 0, "", nextRows);

        for (auto &nr : nextRows) {
            if (solve(nr)) return true;
        }

        bad.insert(row);
        return false;
    }

    void buildNextRows(const string &row, int i, string current, vector<string>& result) {
        if (i == row.size() - 1) {
            result.push_back(current);
            return;
        }

        string pair = row.substr(i, 2);
        if (!mp.count(pair)) return;

        for (char c : mp[pair]) {
            buildNextRows(row, i + 1, current + c, result);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return solve(bottom);
    }
};
