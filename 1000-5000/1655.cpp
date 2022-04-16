#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> mxq;
    priority_queue<int, vector<int>, greater<>> mnq;
    int n; scanf("%d", &n);
    while (n--) {
        int inp; scanf("%d", &inp);
        mnq.size() >= mxq.size() ? mxq.push(inp) : mnq.push(inp);
        if (!mxq.empty() && !mnq.empty() && mxq.top() > mnq.top()) {
            int mxtop = mxq.top(), mntop = mnq.top();
            mxq.pop(); mnq.pop();
            mxq.push(mntop);
            mnq.push(mxtop);
        }
        printf("%d\n", mxq.top());
    }
}