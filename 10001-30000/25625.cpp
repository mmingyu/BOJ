#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 1e8;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b; cin >> a >> b;
    if (b > a) cout << b - a;
    else cout << a + b;
}