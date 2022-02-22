#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll a = n, b = 0, pw = 1;
    while (a) {
      if (a % 2 == 0) b += pw;
      a >>= 1;
      pw <<= 1;  
    }
    if (b) {
        printf("2\n%lld\n%lld", b, n);
    } else {
        printf("1\n%lld", n);
    }
}