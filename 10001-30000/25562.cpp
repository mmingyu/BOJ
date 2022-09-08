#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    cout << n * (n - 1) / 2 << "\n";
    for (int i = 0; i < n; i++) cout << (1 << i) << " ";
    cout << "\n";
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++) cout << i << " ";
}