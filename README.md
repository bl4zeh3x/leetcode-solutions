# LeetCode solutions

Solutions to problems I've worked through on LeetCode. The code is kept close to the accepted submissions, with notes on algorithms and trade-offs where useful.

[LeetCode profile](https://leetcode.com/u/bl4zeh3x/)

| Problem | Name | Difficulty | Language | Source | Accepted submission |
|---|---|---|---|---|---|
| 0001 | Two Sum | Easy | C++ | [Code](solutions/0001-two-sum.cpp) | [2175600903](https://leetcode.com/submissions/detail/2175600903/) |
| 0003 | Longest Substring Without Repeating Characters | Medium | C++ | [Code](solutions/0003-longest-substring-without-repeating-characters.cpp) | [2175599761](https://leetcode.com/submissions/detail/2175599761/) |
| 0011 | Container With Most Water | Medium | C++ | [Code](solutions/0011-container-with-most-water.cpp) | [2175599179](https://leetcode.com/submissions/detail/2175599179/) |
| 1569 | Number of Ways to Reorder Array to Get Same BST | Hard | C++ | [Code](solutions/1569-number-of-ways-to-reorder-array-to-get-same-bst.cpp) | [2175610739](https://leetcode.com/submissions/detail/2175610739/) |

## Recent LeetCode activity awaiting source sync

The repository's solution table above contains files whose source and submission links have been recorded. Additional accepted results were reported in the experiment history, but their exact submitted source has not been retrieved for publication. They are tracked separately rather than replacing original accepted code with reconstructed implementations.

| Problem | Name | Reported language | Submission evidence | Source status |
|---|---|---|---|---|
| 198 | House Robber | Python 3 | [2176030883](https://leetcode.com/submissions/detail/2176030883/) | Original accepted source not yet recovered |
| 209 | Minimum Size Subarray Sum | C++ | [2176045323](https://leetcode.com/submissions/detail/2176045323/), [2176178506](https://leetcode.com/submissions/detail/2176178506/) | Original accepted variants not yet recovered |
| 2089 | Find Target Indices After Sorting Array | Python 3 | [2176025973](https://leetcode.com/submissions/detail/2176025973/) | Original accepted source not yet recovered |
| 2161 | Partition Array According to Given Pivot | Not recovered | Reported 30 October 2026 | Submission ID and source not yet recovered |
| 2574 | Left and Right Sum Differences | Not recovered | Reported 30 October 2026 | Submission ID and source not yet recovered |
| 3970 | Recent accepted problem (title not recovered) | Not recovered | Reported 30 October 2026 | Exact problem details and source not yet recovered |

*Sync audit: 1 November 2026.* These are historical reports, not a live verification of the LeetCode account; current account activity may be newer. The entries above are **not** counted as published solution files. Only add their code after the original accepted source is obtained and checked.

## Notes

- **0001:** Check each complement against earlier values in a hash map before inserting the current index. Expected O(n) time and O(n) space.
- **0003:** A sliding window and a 256-entry last-position table keep the left boundary past repeated characters. O(n) time; the string parameter is passed by value in the accepted code.
- **0011:** Move the shorter boundary inward: retaining it with a smaller width cannot improve the current area. O(n) time and O(1) auxiliary space.
- **1569:** Build the insertion BST as a min Cartesian tree of insertion positions in sorted-key order. A monotonic stack constructs the parents; reverse insertion order accumulates subtree sizes. The count is n! divided by the product of subtree sizes, modulo 1,000,000,007, minus the original ordering. This replaces the earlier quadratic combination table and recursive partitions with O(n) storage and O(n + log MOD) time. The earlier accepted implementation is retained in commit history.

Files use LeetCode's `Solution` interface and rely on the judge's standard-library setup.
