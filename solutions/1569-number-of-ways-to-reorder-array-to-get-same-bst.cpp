class Solution {
    static constexpr long long MOD = 1000000007;
    vector<vector<long long>> choose;
    long long countWays(const vector<int>& values) {
        if (values.size() <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < (int)values.size(); ++i) {
            if (values[i] < values[0]) left.push_back(values[i]);
            else right.push_back(values[i]);
        }
        long long ways = choose[values.size() - 1][left.size()];
        ways = ways * countWays(left) % MOD;
        return ways * countWays(right) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        choose.assign(n + 1, vector<long long>(n + 1));
        for (int i = 0; i <= n; ++i) {
            choose[i][0] = choose[i][i] = 1;
            for (int j = 1; j < i; ++j)
                choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % MOD;
        }
        return (countWays(nums) + MOD - 1) % MOD;
    }
};
