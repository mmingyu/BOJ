#include <bits/stdc++.h>
using namespace std;

int dp[1003][1003];

int main() {
    string a, b; cin >> a >> b;
    a = '%' + a;
    b = '%' + b;
    for (int i = 0; i < max(a.size(), b.size()); i++) dp[0][i] = dp[i][0] = i;

    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
    }

    printf("%d", dp[a.size() - 1][b.size() - 1]);
}