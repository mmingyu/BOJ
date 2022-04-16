#include <bits/stdc++.h>
using namespace std;

const int N = 18000;
int dp[2][N];
unsigned char par[N / 2][N / 2];
string a, b;

int q(int r, int c) {
    int r_mod = r % 2, c_mod = c % 2;
    r = r / 2, c = c / 2;
    int k = par[r][c];
    if (!r_mod && !c_mod) return k & 3;
    else if (!r_mod && c_mod) return (k >> 2) & 3;
    else if (r_mod && c_mod) return (k >> 4) & 3;
    else return (k >> 6) & 3;
}

// m 0, 왼쪽 1, 위 2, c 3

void u(int r, int c, int t) {
    int r_mod = r % 2, c_mod = c % 2;
    r = r / 2, c = c / 2;
    auto &k = par[r][c];

    if (!r_mod && !c_mod) k |= t;
    else if (!r_mod && c_mod) k |= (t << 2);
    else if (r_mod && c_mod) k |= (t << 4);
    else k |= (t << 6);
}

void print(int r, int c) {
    if (!r && !c) return;
    int prv = q(r, c);
    if (prv == 0) {
        print(r - 1, c - 1);
        printf("m %c\n", b[c]);
    } else if (prv == 1) {
        print(r, c - 1);
        printf("a %c\n", b[c]);
    } else if (prv == 2) {
        print(r - 1, c);
        printf("d %c\n", a[r]);
    } else {
        print(r - 1, c - 1);
        printf("c %c\n", a[r]);
    }
}

int main() {
    cin >> a >> b;
    a = '%' + a; b = '%' + b;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        u(0, i, 1);
        u(i, 0, 2);
        dp[0][i] = i;
    }
    
    for (int i = 1; i < a.size(); i++) {
        dp[1][0] = i;
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) {
                dp[1][j] = dp[0][j - 1];
                u(i, j, 3);
            } else {
                dp[1][j] = min({dp[0][j - 1], dp[0][j], dp[1][j - 1]}) + 1;
                if (dp[1][j] == dp[0][j - 1] + 1) u(i, j, 0);
                else if (dp[1][j] == dp[1][j - 1] + 1) u(i, j, 1);
                else u(i, j, 2);
            }
        }
        for (int i = 0; i < b.size(); i++) {
            dp[0][i] = dp[1][i];
            dp[1][i] = 0;
        }
    }
    print(a.size() - 1, b.size() - 1);
}