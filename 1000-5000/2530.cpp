#include <iostream>
using namespace std;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int tot = a * 3600 + b * 60 + c + d;
    cout << tot / 3600 % 24 << " " << tot / 60 % 60 << " " << tot % 60;
}