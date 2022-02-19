#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        int inp; cin >> inp;
        while (!st.empty() && st.top() <= inp) st.pop();
        ans += st.size();
        st.push(inp);
    }    
    cout << ans;
}