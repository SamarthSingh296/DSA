class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int a : apple) totalApples += a;

        // Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        int usedBoxes = 0;
        int currCapacity = 0;

        for (int cap : capacity) {
            currCapacity += cap;
            usedBoxes++;
            if (currCapacity >= totalApples)
                return usedBoxes;
        }

        return -1; // Safety, though constraints usually ensure a solution
    }
};
