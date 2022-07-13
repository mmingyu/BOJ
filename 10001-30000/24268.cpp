#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
int n, d; 

string operator++(string &s) {
    int carry = 1;
    for (int i = sz(s) - 1; i >= 0; i--) {
        if (s[i] + carry - '0' >= d) { 
            s[i] = '0'; 
            carry = 1; 
        } else { 
            s[i] += carry; 
            carry = 0;
            break; 
        }
    }
    if (carry) s = '1' + s;
    return s;
}

bool chk(string s) {
    compress(s);
    return s.size() == d;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> d;
    string x;
    while (n) x.push_back('0' + (n % d)), n /= d;
    reverse(all(x));
    while (x.size() <= d) {
        ++x;
        if (x.size() == d && chk(x)) { 
            int p = 1, ret = 0;
            for (int i = sz(x) - 1; i >= 0; i--) ret += (x[i] - '0') * p, p *= d;
            cout << ret;
            return 0; 
        };
    }
    cout << -1;
}