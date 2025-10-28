class Solution {
public:
    int countValidSelections(vector<int>& nums) {
         int s = 0;
        for (int x : nums) {
            s += x;
        }
        int ans = 0;
        int leftSum = 0;
        for (int x : nums) {
            if (x != 0) {
                leftSum += x;
            } else {
                int rightSum = s - leftSum;
                if (leftSum == rightSum) {
                
                    ans += 2;
                } else if (abs(leftSum - rightSum) == 1) {
                
                    ans += 1;
                }
               
            }
        }
        return ans;
        
    }
};