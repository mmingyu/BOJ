#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> arr(3);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    if (arr[0] == arr[1] & arr[1] == arr[2]) cout << 10000 + arr[0] * 1000;
    else if (arr[0] == arr[1]) cout << 1000 + arr[0] * 100;
    else if (arr[1] == arr[2]) cout << 1000 + arr[1] * 100;
    else cout << arr[2] * 100;
}