class Solution {
public:

    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {

                factors.push_back(i);

                while (x % i == 0)
                    x /= i;
            }
        }

        if (x > 1)
            factors.push_back(x);

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // store indices divisible by prime factor
        for (int i = 0; i < n; i++) {

            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                mp[p].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        vector<int> vis(n, 0);

        q.push({0, 0});
        vis[0] = 1;

        unordered_set<int> usedPrime;

        while (!q.empty()) {

            auto [i, steps] = q.front();
            q.pop();

            if (i == n - 1)
                return steps;

            // adjacent left
            if (i - 1 >= 0 && !vis[i - 1]) {
                vis[i - 1] = 1;
                q.push({i - 1, steps + 1});
            }

            // adjacent right
            if (i + 1 < n && !vis[i + 1]) {
                vis[i + 1] = 1;
                q.push({i + 1, steps + 1});
            }

            // teleportation
            if (isPrime(nums[i])) {

                int p = nums[i];

                if (!usedPrime.count(p)) {

                    usedPrime.insert(p);

                    for (int idx : mp[p]) {

                        if (!vis[idx]) {
                            vis[idx] = 1;
                            q.push({idx, steps + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};