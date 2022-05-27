#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
constexpr int N = 55;
int capacity[N][N];
int flow[N][N];
int par[N];

int ctoi(char c){
    if(c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int network_flow(int src, int sink) {
    int total_flow = 0;
    while (true) {
        memset(par, -1, sizeof(par));
        par[src] = src;
        queue<int> q;
        q.push(src);
        while (!q.empty() && par[sink] == -1) {
            int cur = q.front(); q.pop();
            for (int nxt = 0; nxt < N; nxt++) {
                if (capacity[cur][nxt] - flow[cur][nxt] > 0 && par[nxt] == -1) {
                    q.push(nxt);
                    par[nxt] = cur;
                }
            }
        }
        if (par[sink] == -1) break;
        int min_amount = INF;
        for (int i = sink; i != src; i = par[i]) {
            min_amount = min(min_amount, capacity[par[i]][i] - flow[par[i]][i]);
        }
        for (int i = sink; i != src; i = par[i]) {
            flow[par[i]][i] += min_amount;
            flow[i][par[i]] -= min_amount;
        }
        total_flow += min_amount;
    }
    return total_flow;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b; int c; cin >> a >> b >> c;
        capacity[ctoi(a)][ctoi(b)] += c;
        capacity[ctoi(b)][ctoi(a)] += c;
    }
    cout << network_flow(ctoi('A'), ctoi('Z'));
}