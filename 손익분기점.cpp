#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (b >= c) {
        printf("-1");
    } else {
        printf("%d", a / (c - b) + 1);
    }
}