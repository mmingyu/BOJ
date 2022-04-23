#include <bits/stdc++.h>
using namespace std;

struct T {
    int x, y;
    int p, q;
    T() : T(0, 0, 1, 0) {}
    T(int x, int y): T(x, y, 1, 0) {}
    T(int x, int y, int p, int q): x(x), y(y), p(p), q(q) {}
    bool operator<(const T &a) {
        // q/p가 기울기니까 기울기 순으로 정렬
        if (1LL * q * a.p != 1LL * p * a.q) return 1LL * q * a.p < 1LL * p * a.q;
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
};

long long ccw(const T &a, const T &b, const T &c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

long long dist(const T &a, const T &b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

T arr[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        arr[i] = T(x, y);
    }
    sort(arr, arr + n);
    for (int i = 1; i < n; i++) {
        arr[i].p = arr[i].x - arr[0].x;
        arr[i].q = arr[i].y - arr[0].y;
    }
    sort(arr + 1, arr + n);
    
    vector<int> st;
    st.push_back(0);
    st.push_back(1);
    for (int i = 2; i < n; i++) {
        while (st.size() >= 2) {
            int f = st.back(); st.pop_back();
            int s = st.back();
            if (ccw(arr[s], arr[f], arr[i]) > 0) {
                st.push_back(f);
                break;
            }
        }
        st.push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < st.size(); i++) {
        for (int j = i + 1; j < st.size(); j++) {
            ans = max(ans, dist(arr[st[i]], arr[st[j]]));
        }
    }
    printf("%.7lf", sqrt(ans));
}