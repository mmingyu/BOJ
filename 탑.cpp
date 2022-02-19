#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    stack<pair<int, int>> st;
    st.push({1e9 + 9, 0});
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        while (!st.empty() && st.top().first < inp) st.pop();
        printf("%d ", st.top().second);
        st.push({inp, i});
    }
}
