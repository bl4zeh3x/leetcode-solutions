class Solution {
    static constexpr long long MOD = 1000000007;
    long long power(long long base, long long exponent) {
        long long result = 1;
        while (exponent) {
            if (exponent & 1) result = result * base % MOD;
            base = base * base % MOD;
            exponent >>= 1;
        }
        return result;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<int> position(n + 1), parent(n + 1), size(n + 1, 1), stack;
        stack.reserve(n);
        for (int i = 0; i < n; ++i) position[nums[i]] = i;

        // The insertion BST is the min Cartesian tree of insertion positions
        // in key order: keys are the inorder traversal, earliest key is root.
        for (int key = 1; key <= n; ++key) {
            int last = 0;
            while (!stack.empty() && position[stack.back()] > position[key]) {
                last = stack.back();
                stack.pop_back();
            }
            if (!stack.empty()) parent[key] = stack.back();
            if (last) parent[last] = key;
            stack.push_back(key);
        }

        // Parents were inserted earlier, so reverse insertion order is
        // sufficient to aggregate every child's subtree size first.
        for (int i = n - 1; i > 0; --i)
            size[parent[nums[i]]] += size[nums[i]];

        long long factorial = 1, divisor = 1;
        for (int key = 1; key <= n; ++key) {
            factorial = factorial * key % MOD;
            divisor = divisor * size[key] % MOD;
        }
        // The number of parent-before-descendant orders is n! / product(size).
        long long ways = factorial * power(divisor, MOD - 2) % MOD;
        return (ways + MOD - 1) % MOD;
    }
};
