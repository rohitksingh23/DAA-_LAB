
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int m = s1.length();
    int n = s2.length();

    // Create DP table
    vector<vector<int>> dp(
        m + 1, vector<int>(n + 1, 0)
    );

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    // Length of LCS
    cout << "Length of LCS: " << dp[m][n] << endl;

    // Reconstruct the LCS string
    string lcs = "";
    int i = m;
    int j = n;

    while (i > 0 && j > 0) {

        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}

