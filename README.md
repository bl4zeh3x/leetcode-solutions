# LeetCode solutions

Solutions to problems I've worked through on LeetCode. The code is kept close to the accepted submissions, with notes on algorithms and trade-offs where useful.

[LeetCode profile](https://leetcode.com/u/bl4zeh3x/)

| Problem | Name | Difficulty | Language | Source | Accepted submission |
|---|---|---|---|---|---|
| 0001 | Two Sum | Easy | C++ | [Code](solutions/0001-two-sum.cpp) | [2175600903](https://leetcode.com/submissions/detail/2175600903/) |
| 0003 | Longest Substring Without Repeating Characters | Medium | C++ | [Code](solutions/0003-longest-substring-without-repeating-characters.cpp) | [2175599761](https://leetcode.com/submissions/detail/2175599761/) |
| 0011 | Container With Most Water | Medium | C++ | [Code](solutions/0011-container-with-most-water.cpp) | [2175599179](https://leetcode.com/submissions/detail/2175599179/) |
| 1569 | Number of Ways to Reorder Array to Get Same BST | Hard | C++ | [Code](solutions/1569-number-of-ways-to-reorder-array-to-get-same-bst.cpp) | [2175601326](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/submissions/2175601326/?envType=daily-question&envId=2026-10-18) |

## Notes

- **0001:** Check each complement against earlier values in a hash map before inserting the current index. Expected O(n) time and O(n) space.
- **0003:** A sliding window and a 256-entry last-position table keep the left boundary past repeated characters. O(n) time; the string parameter is passed by value in the accepted code.
- **0011:** Move the shorter boundary inward: retaining it with a smaller width cannot improve the current area. O(n) time and O(1) auxiliary space.
- **1569:** Partition around each root, then interleave the valid left and right orders using precomputed binomial coefficients. Subtract the original ordering. O(n²) worst-case time and space.

Files use LeetCode's `Solution` interface and rely on the judge's standard-library setup.
