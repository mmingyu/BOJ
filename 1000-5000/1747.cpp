#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e6;
int prime[N];

bool is_palin(int n) {
    string s = to_string(n);
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}
int main() {
    fill(prime, prime + N, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j < N; j += i) prime[j] = false;
    }
    int n; cin >> n;
    for (int i = n; i < N; i++) {
        if (prime[i] && is_palin(i)) {
            cout << i;
            return 0;
        }
    }
}