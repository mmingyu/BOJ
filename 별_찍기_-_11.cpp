#include <bits/stdc++.h>
using namespace std;

const int N = 6 * (2 << 9) + 5;

char star[3][6] = {
    "  *  ",
    " * * ",
    "*****"
};

char arr[N][N];

void solve(int n, int r, int c) {
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                arr[r + i][c + j] = star[i][j];
            }
        }
        return;
    }
    
    solve(n / 2, r, c + 3 * n / 2);
    solve(n / 2, r + 3 * n / 2, c);
    solve(n / 2, r + 3 * n / 2, c + 3 * n);
}

int main() {
    memset(arr, ' ', sizeof(arr));
    int n; scanf("%d", &n);
    solve(n / 3, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) printf("%c", arr[i][j]);
        printf("\n");
    }
}