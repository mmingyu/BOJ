#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 6;
bool prime[N];
vector<int> p;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fill(prime + 2, prime + N, true);
    for (int i = 2; i * i < N; i++) if (prime[i]) {
        for (int j = i * i; j < N; j += i) prime[j] = false;
    }
    for (int i = 3; i < N; i++) if (prime[i]) p.push_back(i);
    while (true) {
        int n; cin >> n;
        if (n == 0) return 0;
        for (const int &x : p) {
            if (n - x <= 2) break;
            if (prime[n - x]) {
                printf("%d = %d + %d\n", n, x, n - x);
                break;
            }
        }
    }
}