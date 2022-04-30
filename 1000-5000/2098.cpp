#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
int dp[17][1 << 17], n;
int w[17][17];

int dpf(int cur, int state) {
   int &ret = dp[cur][state];
   if (~ret) return ret;
   if (!state) return !cur ? 0 : INF;
   ret = INF;
   for (int i = 0; i < n; i++) {
      if (!(state & (1 << i)) || !w[i][cur]) continue;
      ret = min(ret, dpf(i, state & ~(1 << i)) + w[i][cur]);
   }
   return ret;
}

int main() {
   memset(dp, -1, sizeof dp);
   scanf("%d", &n);
   for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++) scanf("%d", &w[i][j]);
   printf("%d\n", dpf(0, (1 << n) - 1));
}