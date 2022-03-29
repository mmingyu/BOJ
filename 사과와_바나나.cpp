#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1503;
int A[N][N];
int B[N][N];
int dp[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int r, c; cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            string s; cin >> s;
            A[i][j] = A[i - 1][j];
            B[i][j] = B[i - 1][j];
            if (s[0] == 'A') A[i][j] += stoi(s.substr(1));
            else B[i][j] += stoi(s.substr(1));
        }
    }
    for (int i = 1; i <= r; i++) dp[i][1] = A[r][1] - A[i][1];
    for (int i = 1; i <= c; i++) dp[1][i] = dp[1][i - 1] + A[r][i] - A[1][i];
    
    for (int i = 2; i <= r; i++) {
        for (int j = 2; j <= c; j++) {
            dp[i][j] = max({
                dp[i - 1][j] - (A[i][j] - A[i - 1][j]),
                dp[i][j - 1] + B[i - 1][j] + A[r][j] - A[i][j],
                dp[i - 1][j - 1] + B[i - 1][j] + A[r][j] - A[i][j]
            });
        }
    }
    cout << dp[r][c];
}