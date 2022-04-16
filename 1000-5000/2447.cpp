#include <bits/stdc++.h>
using namespace std;

char ret[7000][7000];
char cashe[3][4] = {
    "***",
    "* *",
    "***"
};

void solve(int r, int c, int n) {
    if (n == 3) {
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            ret[r + i][c + j] = cashe[i][j];
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            solve(r + n / 3 * i, c + n / 3 * j, n / 3);
        }
    }
}

int main() {
    memset(ret, ' ', sizeof(ret));
    int n; cin >> n;
    solve(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%c", ret[i][j]);
        printf("\n");
    }
}