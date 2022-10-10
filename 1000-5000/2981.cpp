#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())

constexpr int N = 102;
int arr[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) if (i != j) {
            v.push_back(abs(arr[i] - arr[j]));
        }
    }
    // cout << v.size() << endl;

    int g = v.size() == 1 ? v[0] : gcd(v[0], v[1]);
    for (int i = 2; i < sz(v); i++) {
        g = gcd(g, v[i]);
    }

    vector<int> ans = {g};

    int sq = sqrt(g);
    for (int i = 2; i <= sq; i++) {
        if (g % i == 0) {
            ans.push_back(i);
            ans.push_back(g / i);
        }
    }

    compress(ans);
    for (const int &x : ans) cout << x << " ";
}