#include <iostream>
#include <cstring>

using namespace std;


int LCSLength(const char* X, const char* Y) {
    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];


    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}


void printLCS(const char* X, const char* Y, int m, int n) {
    int dp[m + 1][n + 1];


    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    int length = dp[m][n];


    char lcs[length + 1];
    lcs[length] = '\0';


    int i = m, j = n;
    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1];
            --i;
            --j;
            --length;
        }

        else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }


    cout << "Longest Common Subsequence: " << lcs << endl;
}

int main() {
    const char* str1 = "ABCD";
    const char* str2 = "ACDF";

    int m = strlen(str1);
    int n = strlen(str2);


    int length = LCSLength(str1, str2);


    printLCS(str1, str2, m, n);

    return 0;
}

