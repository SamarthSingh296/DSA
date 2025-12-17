class Solution {
public:
//     void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
//         if (index == nums.size()) {
//         result.push_back(current);
//         return;
//     }

//     generateSubsets(index + 1, nums, current, result);

//     current.push_back(nums[index]);
//     generateSubsets(index + 1, nums, current, result);

//     current.pop_back();
// }

vector<vector<int>> subsets(vector<int>& nums) {
    // vector<vector<int>> result;
    // vector<int> current;
    // generateSubsets(0, nums, current, result);
    // return result;
    int n=nums.size();
    int sub=1<<n;
    vector<vector<int>>res;
    for(int num=0;num<sub;num++){
        vector<int>list;
        for(int j=0;j<n;j++){
            if((num&(1<<j)))list.push_back(nums[j]);
        }
        res.push_back(list);
    }
    return res;
        
    }
};