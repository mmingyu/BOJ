#include <bits/stdc++.h>
using namespace std;

int arr[444][5];
int mat[22][22];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n; 
int num[5] = {0, 1, 10, 100, 1000};

void solve(int x) {
    pair<int, int> pos = {-1, -1};
    int mx = -1, mx_emty = -1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (mat[i][j]) continue;
        int cnt = 0, emty = 0;
        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if (nr >= n || nr < 0 || nc >= n || nc < 0) continue;
            if (!mat[nr][nc]) emty++;
            for (int l = 0; l < 4; l++) if (mat[nr][nc] == arr[x][l]) cnt++;
        }
        if (cnt > mx || (cnt == mx && emty > mx_emty)) mx = cnt, mx_emty = emty, pos = {i, j};
    }
    mat[pos.first][pos.second] = x;
}

int main() {
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int x; cin >> x;
        for (int j = 0; j < 4; j++) cin >> arr[x][j];
        solve(x);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if (nr >= n || nr < 0 || nc >= n || nc < 0) continue;
            for (int l = 0; l < 4; l++) if (mat[nr][nc] == arr[mat[i][j]][l]) cnt++;
        }
        ans += num[cnt];
    }
    cout << ans;
}