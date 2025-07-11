#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // Empty string matches empty pattern

        // Handle patterns that can match an empty string (like "a*", "a*b*" etc.)
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] != '*') {
                    // Check if current characters match and previous state is true
                    if (s[i-1] == p[j-1] || p[j-1] == '.') {
                        dp[i][j] = dp[i-1][j-1];
                    }
                } else {
                    // Check zero occurrence of the preceding character
                    if (j >= 2) {
                        dp[i][j] = dp[i][j-2];
                    }
                    // Check one or more occurrences of the preceding character
                    if (j >= 2 && (p[j-2] == s[i-1] || p[j-2] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};