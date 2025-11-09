class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
         vector<int> pos, neg;

   
    for (int n : nums) {
        if (n > 0) pos.push_back(n);
        else neg.push_back(n);
    }

    vector<int> result;
    result.reserve(nums.size());

  
    for (int i = 0; i < pos.size(); i++) {
        result.push_back(pos[i]);
        result.push_back(neg[i]);
    }

    return result;
    }
};