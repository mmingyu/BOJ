#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int cnt[N], arr[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < n; i++) {
        int cal = arr[i];
        for (int j = 2; j <= arr[i]; j++) {
            while (cal % j == 0) {
                cal /= j;
                cnt[j]++;
            }
        }
    }
    
    int ans = 1;
    vector<int> facs;
    for (int i = 2; i < N; i++) {
        if (cnt[i] / n) {
            for (int j = 0; j < (cnt[i] / n); j++) {
                facs.push_back(i);
                ans *= i;
            }
        }
    }

    int ans_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : facs) {
            if (arr[i] % x) ans_cnt++;
            else arr[i] /= x;
        }
    }
    printf("%d %d", ans, ans_cnt);
}