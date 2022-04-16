#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int tot = a * 60 + b + c;
    cout << tot / 60 % 24 << " " << tot % 60;
}