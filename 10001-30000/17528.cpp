#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define endl '\n'

constexpr int N = 255;
constexpr int of = N * N;
int dp[N][2*N*N]; 
int a[N], b[N];

// i번째까지 봤을때 sum(a) - sum(b)가 j 
// sum(a)-> 0..i-1에서 a를 고른 놈들의 합 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    fill(&dp[0][0], &dp[N][0], 1e9);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    dp[1][-b[1] + of] = b[1];
    dp[1][a[1] + of] = a[1];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < of+of; j++) {
            if (dp[i][j] == 1e9) continue;
            // a가 더 컸는데 a를 또 고를때 -> dp식에 그대로 a값 더함
            if (int x = j + a[i+1]; j >= of)
                dp[i+1][x] = min(dp[i+1][x], dp[i][j] + a[i+1]);            
            // b가 더 컸는데 b를 또 고를때
            if (int x = j - b[i+1]; j <= of)
                dp[i+1][x] = min(dp[i+1][x], dp[i][j] + b[i+1]);
            // a가 더 컷는데 b를 고를때 -> 차 계산해서 더함
            if (int x = j - b[i+1]; j >= of)
                dp[i+1][x] = min(dp[i+1][x], dp[i][j] + max(0, b[i+1] - (j - of)));
            // b가 더 컷는데 a를 고를때
            if (int x = j + a[i+1]; j <= of)
                dp[i+1][x] = min(dp[i+1][x], dp[i][j] + max(0, a[i+1] + j - of));
            
        }
    }
 
    cout << *min_element(dp[n], dp[n] + 2*of) << endl;
}