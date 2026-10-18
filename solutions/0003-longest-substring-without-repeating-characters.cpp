class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> last;
        last.fill(-1);
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            unsigned char c = s[right];
            left = max(left, last[c] + 1);
            last[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
