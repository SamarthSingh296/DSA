class Solution {
public:
    int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>matrices;
        for(int row=0;row<numRows;row++){
               vector<int> arr;
        for (int i = 0; i <= row; i++)
            arr.push_back(binomialCoeff(row, i));

        matrices.push_back(arr);
    }
    return matrices;
}
        
};